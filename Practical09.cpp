/*
Implement Travelling salesman problem using branch and bound approach using C++.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
const int INF = INT_MAX;
class Graph
{
public:
    int V;
    vector<vector<int>> graph;
    Graph(int V)
    {
        this->V = V;
        graph.assign(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v, int w)
    {
        graph[u][v] = w;
        graph[v][u] = w;
    }
};
struct Node
{
    int level, city;
    vector<int> path;
    int cost;
    Node(int level, int city, const vector<int> &path, int cost)
        : level(level), city(city), path(path), cost(cost) {}
};
struct MinHeapComparator
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.cost > b.cost;
    }
};
int tspBranchAndBound(Graph &G, int start)
{
    int n = G.V;
    vector<int> minOutboundEdge(n, INF);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (G.graph[u][v] < minOutboundEdge[u] && u != v)
            {
                minOutboundEdge[u] = G.graph[u][v];
            }
        }
    }
    int finalMinCost = INF;
    priority_queue<Node, vector<Node>, MinHeapComparator> pq;
    vector<int> initialPath;
    initialPath.push_back(start);
    Node root(0, start, initialPath, 0);
    root.cost = 0;
    pq.push(root);
    while (!pq.empty())
    {
        Node top = pq.top();
        pq.pop();
        int level = top.level;
        int city = top.city;
        vector<int> path = top.path;
        if (level == n - 1)
        {
            path.push_back(path[0]); // Return to starting city
            int currentCost = top.cost + G.graph[city][path[0]];
            finalMinCost = min(finalMinCost, currentCost);
        }
        for (int nextCity = 0; nextCity < n; nextCity++)
        {
            if (G.graph[city][nextCity] != 0 && find(path.begin(), path.end(), nextCity) == path.end())
            {
                int currentCost = top.cost + G.graph[city][nextCity];
                int bound = currentCost + minOutboundEdge[nextCity];
                if (bound < finalMinCost)
                {
                    vector<int> newPath = path;
                    newPath.push_back(nextCity);
                    Node child(level + 1, nextCity, newPath, currentCost);
                    child.cost = currentCost;
                    pq.push(child);
                }
            }
        }
    }
    return finalMinCost;
}
int main()
{
    int V;
    cout << "Enter the number of cities: ";
    cin >> V;
    Graph G(V);
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> G.graph[i][j];
        }
    }
    int startCity;
    cout << "Enter the starting city (0 to " << V - 1 << "): ";
    cin >> startCity;
    int minCost = tspBranchAndBound(G, startCity);
    cout << "Minimum cost of the TSP tour: " << minCost << endl;
    return 0;
}

/*
Best Case: O(1) - When the optimal solution is found early.
Average Case: O((V-1)!) - Considering exploring a significant portion of the solution space.
Worst Case: O((V-1)!) - When exploring the entire solution space.
*/

/*
Output:
Enter the number of cities: 4
Enter the adjacency matrix for the graph:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Enter the starting city (0 to 3): 0
Minimum cost of the TSP tour: 80
*/

