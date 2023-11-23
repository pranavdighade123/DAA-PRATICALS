/*
From a given vertex in a weighted connected graph, find shortest paths to other vertices
using Dijkstra's algorithm. Write the program in C++.
*/


#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
const int INF = INT_MAX;

class Graph
{
public:
    int V;                              // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming an undirected graph
    }
    void dijkstra(int src)
    {
        vector<int> dist(V, INF);
        set<pair<int, int>> s;
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty())
        {
            pair<int, int> tmp = *(s.begin());
            s.erase(s.begin());
            int u = tmp.second;
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = i->first;
                int weight = i->second;
                if (dist[v] > dist[u] + weight)
                {
                    if (dist[v] != INF)
                        s.erase(s.find({dist[v], v}));
                    dist[v] = dist[u] + weight;
                    s.insert({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the source vertex
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Graph g(V);
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    g.dijkstra(src);
    return 0;
}

/*
Best Case: O((V + E) * log(V))
Average Case: O((V + E) * log(V))
Worst Case: O((V + E) * log(V))
*/

/*
Output:
Enter the number of vertices and edges: 5 7
Enter the edges (source, destination, weight):
0 1 4
0 2 2
1 2 5
1 3 10
2 3 3
2 4 2
3 4 7
0 1 4
0 2 2
1 2 5
1 3 10
2 3 3
2 4 2
3 4 7
Enter the source vertex:
0
Vertex Distance from Source
0 0
1 4
2 2
3 5
4 4
*/