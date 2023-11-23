/*
Write C++ program to implement Travelling Sales Person problem using Dynamic
programming.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int INF = INT_MAX;
int tsp(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> cities;
    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            cities.push_back(i);
        }
    }
    int minTourCost = INF;
    do
    {
        int currentTourCost = 0;
        int currentCity = start;
        for (int i = 0; i < n - 1; i++)
        {
            int nextCity = cities[i];
            currentTourCost += graph[currentCity][nextCity];
            currentCity = nextCity;
        }
        currentTourCost += graph[currentCity][start];
        minTourCost = min(minTourCost, currentTourCost);
    } while (next_permutation(cities.begin(), cities.end()));
    return minTourCost;
}
int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int start;
    cout << "Enter the starting city (0 to " << n - 1 << "): ";
    cin >> start;
    int minTourCost = tsp(graph, start);
    cout << "Minimum tour cost: " << minTourCost << endl;
    return 0;
}

/*
Best Case: O(n!)
Average Case: O(n!)
Worst Case: O(n!)
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
Minimum tour cost: 80
*/