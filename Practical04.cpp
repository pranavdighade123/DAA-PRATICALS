/*
A business house has several offices in different countries, they want to lease phone lines
to connect them with each other and the phone company charges different rent to connect
different pairs of cities. Business house want to connect all its offices with a minimum total
cost. Solve the problem by suggesting appropriate data structures in C++.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

int findParent(vector<int> &parent, int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}


void unionSets(vector<int> &parent, int u, int v) {
    int uParent = findParent(parent, u);
    int vParent = findParent(parent, v);
    parent[uParent] = vParent;
}


vector<Edge> findMST(vector<Edge> &edges, int numVertices) {
    vector<Edge> result;  
    vector<int> parent(numVertices, -1);

   
    sort(edges.begin(), edges.end(), compareEdges);

    for (const Edge &edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent) {
            result.push_back(edge);
            unionSets(parent, uParent, vParent);
        }
    }

    return result;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of offices (vertices): ";
    cin >> numVertices;
    cout << "Enter the number of connections (edges): ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);
    cout << "Enter connections (source, destination, rent):\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> minimumSpanningTree = findMST(edges, numVertices);

    cout << "Minimum Spanning Tree edges:\n";
    for (const Edge &edge : minimumSpanningTree) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}

/*
Best Case: O(E log E)
Average Case: O(E log E)
Worst Case: O(E log E)
*/

/*
Output:
Enter the number of offices (vertices): 4
Enter the number of connections (edges): 5
Enter connections (source, destination, rent):
0 1 2
0 2 3
0 3 1
1 2 4
2 3 5
Minimum Spanning Tree edges:
0 - 3 : 1
0 - 1 : 2
0 - 2 : 3
*/

