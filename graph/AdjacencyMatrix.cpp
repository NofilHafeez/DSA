#include <iostream>
using namespace std;

class AdjacencyMatrixUndirected {
public:
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
        matrix[v2][v1] = 1;
    }

    void findDegree(int v) {
        int degree = 0;
        int degree = 0;
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

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);

    graph.outputGraph();
}