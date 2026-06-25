#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;
#include <climits>

struct Vertex; // forward declaration

//  Edge structure
struct Edge {
    Vertex* dest;   // connected vertex
    Vertex* src;    // source vertex
    Edge* next;
    int weight;

    Edge(Vertex* d, Vertex* s, int w = 0) {
        dest = d;
        src = s;
        weight = w;
        next = nullptr;
    }
};

// Vertex structure
struct Vertex {
    string name;
    Edge* edgeList;   // adjacency list
    Vertex* next;     // next vertex in graph
    bool visited;

    Vertex(string n) {
        name = n;
        edgeList = nullptr;
        next = nullptr;
        visited = false;
    }
};


struct HeapNode {
    Vertex* src;
    Vertex* dest;
    int weight;

    HeapNode(Vertex* s, Vertex* d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

class Graph {
public:
    Vertex* head;
    vector<HeapNode> heap;

    


    Graph() {
        head = nullptr;
    }

    // Add Vertex (Course)
    void addVertex(string name) {
        Vertex* newV = new Vertex(name);

        if (!head) {
            head = newV;
        } else {
            Vertex* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newV;
        }
    }

    void removeVertex(string name) {
        if (!head) return;

        Vertex* temp = head;
        bool found = false;

        while (temp != nullptr)
        {
            if (temp->name == name) {
                found = true;
                Edge* edgeList = temp->edgeList;
                while (edgeList != nullptr)
                {
                    Edge* next = edgeList->next;
                    delete edgeList;
                    edgeList = next;
                }
            }
            temp = temp->next;
        }

        if (!found){
            cout << "No element found";
            return;
        }
        

        while (head && head->name == name) {
            Vertex* del = head;
            head = head->next;
            delete del;
        }

        Vertex* current = head;
        while (current && current->next) {
            if (current->next->name == name) {
                Vertex* del = current->next;
                current->next = del->next;
                delete del;
            } else {
                current = current->next;
            }
        }
}

    //  Find Vertex
    Vertex* findVertex(string name) {
        Vertex* temp = head;
        while (temp) {
            if (temp->name == name) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    //  Add Edge 
    void addEdge(string from, string to, int weight = 0) {
        Vertex* v1 = findVertex(from);
        Vertex* v2 = findVertex(to);

        if (!v1 || !v2) {
            cout << "Vertex not found\n";
            return;
        }

        // Add edge v1 → v2
        Edge* newEdge = new Edge(v2, v1, weight);
        newEdge->next = v1->edgeList;
        v1->edgeList = newEdge;

        // For undirected graph: also v2 → v1
        Edge* newEdge2 = new Edge(v1, v2, weight);
        newEdge2->next = v2->edgeList;
        v2->edgeList = newEdge2;
    }  
    
    void removeEdge(string from, string to) {
        Vertex* v1 = findVertex(from);
        Vertex* v2 = findVertex(to);

        if (!v1 || !v2) {
            cout << "Vertex not found\n";
            return;
        }

        // Remove edge v1 → v2
        Edge* current = v1->edgeList;
        Edge* prev = nullptr;
        while (current) {
            if (current->dest == v2) {
                if (prev) prev->next = current->next;
                else v1->edgeList = current->next;
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }

        // For undirected graph: also remove v2 → v1
        current = v2->edgeList;
        prev = nullptr;
        while (current) {
            if (current->dest == v1) {
                if (prev) prev->next = current->next;
                else v2->edgeList = current->next;
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }   
    }

    void findDegree(string v) {
        Vertex* vertex = findVertex(v);
        if (!vertex) {
            cout << "Vertex not found\n";
            return;
        }

        int degree = 0;
        Edge* temp = vertex->edgeList;
        while (temp) {
            degree++;
            temp = temp->next;
        }
        cout << "Degree of vertex " << v << " is: " << degree << endl;
    } 

    void findPath(string from, string to) {
        stack<Vertex*> s;
        unordered_map<Vertex*, Vertex*> parent; // to reconstruct path
        Vertex* v1 = findVertex(from);
        Vertex* v2 = findVertex(to);

        if (!v1 || !v2) {
            cout << "Vertex not found\n";
            return;
        }

        Vertex* start = v1;
        start->visited = true;
        s.push(start);
        parent[start] = nullptr; // start has no parent

        while (!s.empty()) {
            Vertex* current = s.top();
            s.pop();

            if (current == v2) {
                vector<string> vt;
                // v = v2 = URDU

                // vt.push_back(v->name);   // "URDU"
                // v = parent[v];           // v = parent[URDU] = CAL
                // Now v becomes CAL

                // vt.push_back(v->name);   // "CAL"
                // v = parent[v];           // v = parent[CAL] = OOP

                // Now v becomes OOP


                for (Vertex* v = v2; v != nullptr; v = parent[v]) {
                    vt.push_back(v->name);
                }
                reverse(vt.begin(), vt.end());

                for (auto name : vt) {
                    cout << name << " - ";
                }

                cout << endl;
                resetVisited();
                return;
            }
            
            Edge* edge = current->edgeList;
            while (edge != nullptr) {
                if (!edge->dest->visited) {
                    edge->dest->visited = true;
                    parent[edge->dest] = current;
                    s.push(edge->dest);
                }
                edge = edge->next;
            }
        }

        resetVisited();

    }

    void resetVisited() {
    Vertex* temp = head;
    while (temp) {
        temp->visited = false;
        temp = temp->next;
    }
}

    void BFS() {
        queue<Vertex*> q;

        Vertex* start = head;
        start->visited = true;
        q.push(start);

        while (!q.empty()) {
            Vertex* current = q.front();
            q.pop();

            cout << current->name << " ";

            Edge* edge = current->edgeList;
            while (edge != nullptr) {
                if (!edge->dest->visited) {
                    edge->dest->visited = true;
                    q.push(edge->dest);
                }
                edge = edge->next;
            }
        }
    }

    void DFS() {
        stack<Vertex*> s;

        Vertex* start = head;
        start->visited = true;
        s.push(start);

        while (!s.empty()) {
            Vertex* current = s.top();
            s.pop();

            cout << current->name << " ";

            Edge* edge = current->edgeList;
            while (edge != nullptr) {
                if (!edge->dest->visited) {
                    edge->dest->visited = true;
                    s.push(edge->dest);
                }
                edge = edge->next;
            }
        }
    }

    // Print Graph
    void print() {
        Vertex* temp = head;

        while (temp) {
            cout << temp->name << " -> ";

            Edge* e = temp->edgeList;
            while (e) {
                cout << e->dest->name << " -> ";
                e = e->next;
            }

            cout << "NULL\n";
            temp = temp->next;
        }
    }
    
    bool isConnected(string s1, string s2) {
        Vertex* v1 = findVertex(s1);
        Vertex* v2 = findVertex(s2);

        int count = 0;
        Edge* temp = v1->edgeList;
        while (temp != nullptr)  
        {
            if (temp->dest == v2) {
                count++;
            }
            temp = temp -> next;
        }

        Edge* temp2 = v2->edgeList;
        while (temp2 != nullptr)  
        {
            if (temp2->dest == v1) {
                count++;
            }
            temp2 = temp2 -> next;

        }
        
       if (count == 2 ) return true;
       else return false;
    }

    void findNeighbour(Vertex* v) {
        Edge* temp = v->edgeList;
        while (temp != nullptr) {
            cout << temp->dest->name << " ";
            temp = temp->next;
        }
    }

    bool isAdjacent(Vertex* v1, Vertex* v2) {
        Edge* temp = v1->edgeList;
        while (temp != nullptr) {
            if (temp->dest == v2) return true;
            temp = temp->next;
        }
        return false;
    }

    bool isCycle(Vertex* head) {
    stack<pair<Vertex*, Vertex*>> s;
    // (current, parent)

    s.push({head, nullptr});
    head->visited = true;

    while (!s.empty()) {
        pair<Vertex*, Vertex*> p = s.top();
        Vertex* current = p.first;
        Vertex* parent = p.second;
        s.pop();

        Edge* edge = current->edgeList;

        while (edge != nullptr) {
            Vertex* neigh = edge->dest;

            if (!neigh->visited) {
                neigh->visited = true;
                s.push(make_pair(neigh, current));
            }
            else if (neigh != parent) {
                resetVisited();
                return true; // cycle detected
            }

            edge = edge->next;
        }
    }

    resetVisited();
    return false;
}

// visited + not parent = cycle
// visited + parent = ignore
    
    bool isGraphConnected() {
        if (!head) return true; // Empty graph is connected

        resetVisited();
        stack<Vertex*> s;
        s.push(head);
        head->visited = true;

        int visitedCount = 1;
        while (!s.empty()) {
            Vertex* current = s.top();
            s.pop();

            Edge* edge = current->edgeList;
            while (edge != nullptr) {
                if (!edge->dest->visited) {
                    edge->dest->visited = true;
                    s.push(edge->dest);
                    visitedCount++;
                }
                edge = edge->next;
            }
        }

        resetVisited();
        return visitedCount == getVertexCount();
    }

    int getVertexCount() {
        int count = 0;
        Vertex* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void heapInsert(Vertex* src, Vertex* dest, int weight) {
    heap.push_back(HeapNode(src, dest, weight));

    int i = heap.size() - 1;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].weight > heap[i].weight) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

        void heapifyDown(int i) {
    int size = heap.size();

    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left].weight < heap[smallest].weight)
            smallest = left;

        if (right < size && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}
        HeapNode extractMin() {
    HeapNode minNode = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);

    return minNode;
}

     void primsAlgo() {
        Vertex* start = head;
        start->visited = true;

        cout << "MST Edges:\n";

        // push all edges of start node
        Edge* edge = start->edgeList;
        while (edge != nullptr) {
            heapInsert(start, edge->dest, edge->weight);
            edge = edge->next;
        }

        while (!heap.empty()) {
            HeapNode minEdge = extractMin();

            Vertex* v = minEdge.dest;

            // skip visited nodes
            if (v->visited)
                continue;

            // include edge in MST
            cout << minEdge.src->name << " -> "
                << v->name << " : "
                << minEdge.weight << endl;

            v->visited = true;

            // push all edges of new vertex
            Edge* temp = v->edgeList;
            while (temp != nullptr) {
                if (!temp->dest->visited) {
                    heapInsert(v, temp->dest, temp->weight);
                }
                temp = temp->next;
            }
    }
}
// void kruskalsAlgo() {
//     vector<Edge*> edges;
//     vector<Edge*> mst;

//     // Step 1: Collect all edges
//     Vertex* temp = head;
//     while (temp) {
//         Edge* edge = temp->edgeList;
//         while (edge) {
//             edges.push_back(edge);
//             edge = edge->next;
//         }
//         temp = temp->next;
//     }

//     // Step 2: Sort edges by weight
//     sort(edges.begin(), edges.end(), [](Edge* a, Edge* b) {
//         return a->weight < b->weight;
//     });

//     // Step 3: Disjoint Set
//     unordered_map<Vertex*, Vertex*> parent;

//     // initialize parent
//     temp = head;
//     while (temp) {
//         parent[temp] = temp;
//         temp = temp->next;
//     }

//     // Find function
//     function<Vertex*(Vertex*)> find = [&](Vertex* v) {
//         if (parent[v] == v) return v;
//         return parent[v] = find(parent[v]);
//     };

//     // Union function
//     auto unionSet = [&](Vertex* a, Vertex* b) {
//         Vertex* pa = find(a);
//         Vertex* pb = find(b);
//         parent[pa] = pb;
//     };

//     // Step 4: Process edges
//     for (Edge* edge : edges) {
//         Vertex* u = edge->src;   // 
//         Vertex* v = edge->dest;

//         if (find(u) != find(v)) {
//             mst.push_back(edge);
//             unionSet(u, v);
//         }

//         if (mst.size() == getVertexCount() - 1)
//             break;
//     }

//     // Print MST
//     cout << "MST:\n";
//     for (auto e : mst) {
//         cout << e->src->name << " - "
//              << e->dest->name << " : "
//              << e->weight << endl;
//     }
// }
    
void dijkstra(string startName) {
    Vertex* start = findVertex(startName);
    if (!start) return;

    unordered_map<Vertex*, int> dist;
    unordered_map<Vertex*, bool> visited;

    // Step 1: initialize
    Vertex* temp = head;
    while (temp) {
        dist[temp] = INT_MAX;
        visited[temp] = false;
        temp = temp->next;
    }

    dist[start] = 0;

    // Step 2: repeat for all vertices
    for (int i = 0; i < getVertexCount(); i++) {

        // find smallest unvisited
        Vertex* current = nullptr;
        int minDist = INT_MAX;

        temp = head;
        while (temp) {
            if (!visited[temp] && dist[temp] < minDist) {
                minDist = dist[temp];
                current = temp;
            }
            temp = temp->next;
        }

        if (!current) break;

        visited[current] = true;

        cout << current->name << " (" << dist[current] << ") -> ";

        // Step 3: update neighbors
        Edge* edge = current->edgeList;
        while (edge) {
            Vertex* v = edge->dest;

            if (!visited[v] && dist[current] + edge->weight < dist[v]) {
                dist[v] = dist[current] + edge->weight;
            }

            edge = edge->next;
        }
    }
}
};





int main() {
    Graph g;

    g.addVertex("OOP");
    g.addVertex("DSA");
    g.addVertex("DB");
    g.addVertex("CAL");
    g.addVertex("URDU");



    g.addEdge("OOP", "DSA", 4);
    g.addEdge("DSA", "DB", 2);
    g.addEdge("DSA", "CAL", 3);
    g.addEdge("CAL", "URDU", 1);
    g.addEdge("OOP", "CAL", 9);
    g.addEdge("DB", "CAL", 10);



    // g.primsAlgo();
    g.dijkstra("OOP");

    return 0;
}


