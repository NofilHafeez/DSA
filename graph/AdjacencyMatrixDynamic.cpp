#include <iostream>
using namespace std;
#include <vector>

class AdjacencyMatrixUndirectedDynamic {
public:
    int vertices;
    vector<vector<int>> matrix;

    AdjacencyMatrixUndirectedDynamic(int v) {
        vertices = v;
        matrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int v1, int v2) {
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }


    void findDegree(int v) {
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
    AdjacencyMatrixUndirectedDynamic graph(3);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);

    graph.outputGraph();
}