#include <iostream>
using namespace std;
#include <vector>
   #include <queue>
   #include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


struct Node {
    int data;
    Node* left;
    Node* right;
};


struct Node2 {
    int data;
    Node2* child[4];

    Node2(int val) {
        data = val;
        for (int i = 0; i < 4; i++)
            child[i] = nullptr;
    }
};



class Tree
{
public:
    Node* topRoot = nullptr;
    vector<float> arr;  

    Node* insert(Node* root, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (root == nullptr) {
        topRoot = newNode;
        return newNode;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left == nullptr) {
            current->left = newNode;
            break;
        } else {
            q.push(current->left);
        }

        if (current->right == nullptr) {
            current->right = newNode;
            break;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

    void bfs(Node* root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    } 

    


    
    
    void mirror(Node* head) {
    if (head == nullptr)
        return;

    Node* temp = head->left;
    head->left = head->right;
    head->right = temp;

    mirror(head->left);
    mirror(head->right);
}


    void binary (float value) {
        arr.push_back(value);
    }

    // void mirror() {
    //     // 89 122 12 75  99  68
    //     // 89 12 122 75  99  68

    //     // 89 12 122 68  99  75
    //     // 1  2   3   4  5   6


        
    //  // 1 2 3 4 5 6 7

    //     for (int i = 1; i <= arr.size() ; i ++)
    //     {
    //         int child1, child2;
    //         if (i == 1) {
    //             child1 = 2 * i ;
    //             child2 = 2 * i + 1;
    //         }
    //         if (i > 1) {
    //             child1 = 2 * i ;
    //             if (arr.size() % 2 == 1) {
    //             child2 = 2 * (i + 1)  ;
                    
    //             } else {
    //             child2 = 2 * (i + 1)  + 1;

    //             }
    //         }
    //         if (child1 >= arr.size() || child2 >= arr.size()) {
    //             cout << "child1: " << child1 << " child2: " << child2 << endl;  
    //             break;
    //         }
    //         cout << "child1: " << child1 << " child2: " << child2 << endl;
    //         swap (arr[child1], arr[child2]);

    //     }

    //     for (int i = 1; i < arr.size(); i++) {
    //         cout << arr[i] << " ";
    //     }
        
    // }




  
void preorder(Node2* root) {

        if (root == nullptr)
            return;

        cout << root->data << " ";

        for (int i = 0; i < 4; i++)
            preorder(root->child[i]);
    }

};


struct Edge {
    struct Vertex* dest;
    Edge* next;
    Edge(Vertex* d, Edge* n = nullptr) : dest(d), next(n) {}
};

struct Vertex {
    int row, col, value;
    bool visited;
    Vertex* parent;   // used to reconstruct the path after BFS
    Vertex* next;     // linked-list of all vertices
    Edge* edgeList;   // adjacency list (edges to neighbors)

    Vertex(int r, int c, int v)
        : row(r), col(c), value(v), visited(false),
          parent(nullptr), next(nullptr), edgeList(nullptr) {}
};

class AdjacencyUndirected {
public:
    Vertex* head = nullptr;

    void addVertexAdjacencyList(int row, int col, int value) {
        Vertex* newV = new Vertex(row, col, value);
        if (!head) {
            head = newV;
        } else {
            Vertex* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newV;
        }
    }

    Vertex* findVertex(int row, int col) {
        for (Vertex* temp = head; temp; temp = temp->next)
            if (temp->row == row && temp->col == col) return temp;
        return nullptr;
    }

    // Build adjacency list, only connecting open cells (value == 0)
    void intoAdjacencyList() {
        for (Vertex* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->value == 1) continue; // blocked cell

            for (Vertex* other = head; other != nullptr; other = other->next) {
                if (other->value == 1) continue;
                if (temp == other) continue;

                if (abs(temp->row - other->row) <= 1 &&
                    abs(temp->col - other->col) <= 1) {
                    Edge* e = new Edge(other, temp->edgeList);
                    temp->edgeList = e;
                }
            }
        }
    }

    // Reset visited/parent before a fresh BFS run
    void resetSearchState() {
        for (Vertex* temp = head; temp; temp = temp->next) {
            temp->visited = false;
            temp->parent = nullptr;
        }
    }

    void BFS(int startRow, int startCol, int destRow, int destCol) {
        resetSearchState();

        Vertex* start = findVertex(startRow, startCol);
        Vertex* dest  = findVertex(destRow, destCol);

        if (!start || start->value == 1) {
            cout << "Start position is blocked or missing.\n";
            return;
        }
        if (!dest || dest->value == 1) {
            cout << "Destination is blocked or missing.\n";
            return;
        }

        queue<Vertex*> q;
        start->visited = true;      // mark start visited immediately
        q.push(start);

        while (!q.empty()) {
            Vertex* current = q.front();
            q.pop();

            if (current->row == destRow && current->col == destCol) {
                printPath(current);
                return;
            }

            for (Edge* edge = current->edgeList; edge != nullptr; edge = edge->next) {
                if (!edge->dest->visited) {
                    edge->dest->visited = true;
                    edge->dest->parent = current;   // track how we got here
                    q.push(edge->dest);
                }
            }
        }

        cout << "No path found from (" << startRow << "," << startCol
             << ") to (" << destRow << "," << destCol << ").\n";
    }

private:
    // Walk parent pointers back to start, then print in order
    void printPath(Vertex* dest) {
        vector<Vertex*> path;
        for (Vertex* v = dest; v != nullptr; v = v->parent)
            path.push_back(v);
        reverse(path.begin(), path.end());

        cout << "Path found: ";
        for (Vertex* v : path)
            cout << "(" << v->row << "," << v->col << ") ";
        cout << endl;
    }
};

int main() {
    AdjacencyUndirected graph;

    graph.addVertexAdjacencyList(0, 0, 0);
    graph.addVertexAdjacencyList(0, 1, 1);
    graph.addVertexAdjacencyList(0, 2, 0);
    graph.addVertexAdjacencyList(1, 0, 0);
    graph.addVertexAdjacencyList(1, 1, 0);
    graph.addVertexAdjacencyList(1, 2, 1);
    graph.addVertexAdjacencyList(2, 0, 1);
    graph.addVertexAdjacencyList(2, 1, 1);
    graph.addVertexAdjacencyList(2, 2, 0);

    graph.intoAdjacencyList();
    graph.BFS(0, 0, 2, 2);

    return 0;
}




// int main () {
//     // Tree tree = Tree();

//     // Node* root = tree.insert(tree.topRoot, 89);
    
//     // tree.insert(root, 122);
//     // tree.insert(root, 12);
//     // tree.insert(root, 75);
//     // tree.insert(root, 99);
//     // tree.insert(root, 68);



//     // tree.bfs(root);
//     // tree.mirror(root);
//     // tree.bfs(root);


//     // vector<int> arr =
//     // {
//     //     22,44,75,90,92,99,110,112,125,130,131
//     // };

//     // Tree t;

//     // Node2* root = t.build(arr);

//     // cout << "Preorder:\n";
//     // t.preorder(root);



//     // tree.binary(0);
//     // tree.binary(1);
//     // tree.binary(2);
//     // tree.binary(3);
//     // tree.binary(4);
//     // tree.binary(5);
//     // tree.binary(6);
//     // tree.binary(7);


//     // tree.binary(0);
//     // tree.binary(15);
//     // tree.binary(20);
//     // tree.binary(10);
//     // tree.binary(25);
//     // tree.binary(8);
//     // tree.binary(22);
//     // tree.mirror();
//     // 15 10 20


// };

