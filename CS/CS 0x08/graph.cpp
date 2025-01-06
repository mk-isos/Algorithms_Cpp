#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);  // 무방향 그래프
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "노드 " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "그래프 인접 리스트 출력:\n";
    g.printGraph();
    return 0;
}