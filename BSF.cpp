#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int> > adj; 
public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming an undirected graph
    }

    // Breadth-First Search algorithm
    void BFS(int start) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        // 'i' will be used to get all adjacent vertices of a vertex
        while (!q.empty()) {
            // Dequeue a vertex from the queue and print it
            start = q.front();
            cout << start << " ";
            q.pop();

            // Get all adjacent vertices of the dequeued vertex start.
            // If an adjacent has not been visited, then mark it visited
            // and enqueue it
            for (int i = 0; i < adj[start].size(); ++i) {
                int neighbor = adj[start][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Create a graph
    Graph g(numVertices);

    // Input neighbors for each vertex
    for (int i = 0; i < numVertices; ++i) {
        int numNeighbors;
        cout << "Enter the number of neighbors for vertex " << i << ": ";
        cin >> numNeighbors;

        cout << "Enter the neighbors of vertex " << i << ": ";
        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            cin >> neighbor;
            g.addEdge(i, neighbor);
        }
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS starting from vertex " << startVertex << ": ";
    g.BFS(startVertex);

    return 0;
}
