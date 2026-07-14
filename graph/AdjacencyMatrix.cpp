#include <iostream>
using namespace std;
#include <queue>

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



class AdjacencyMatrixUndirected {
public:
    Vertex* head;
    int vertices;
    int matrix[10][10]; // fixed max size

    AdjacencyMatrixUndirected(int v) {
        vertices = v;
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                matrix[i][j] = 0;
            }
        }   
    }

    void addEdge(int v1, int v2) {
        matrix[v1][v2] = 1;
        // matrix[v2][v1] = 1;
    }

    void addVertexAdjacencyList(string name) {
        Vertex* newV = new Vertex(name);

        if (!head) {
            head = newV;
        } else {
            Vertex* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newV;
        }
    }


    void findPath() {
        for (int i = 0; i < 20; i++)
        {
            
        }
        
    }


    void findDegree(int v) {
        int degree = 0;
        // int degree = 0;
        for(int i = 0; i < vertices; i++) {
            if(matrix[v][i] == 1) degree++;
        }
        cout << "Degree of vertex " << v << " is: " << degree << endl;
    }

    void outputGraph() {
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    AdjacencyMatrixUndirected graph(3);

    // graph.addEdge(0, 1);
    graph.addEdge(2, 1);
    graph.addEdge(2, 0);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1);
    graph.addEdge(2, 1);

    graph.outputGraph();

    cout << endl;




}