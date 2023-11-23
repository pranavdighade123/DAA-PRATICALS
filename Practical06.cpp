/*
Implement a program in C++ for 0/1 Knapsack problem using Dynamic Programming
method. 
*/

#include <iostream>
#include <vector>
using namespace std;
int knapsack(int W, vector<int> &weights, vector<int> &values)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    cout << "Enter the weights of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter the values of the items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;
    int maxValue = knapsack(W, weights, values);
    cout << "The maximum value that can be obtained is: " << maxValue << endl;
    return 0;
}

/*
Best Case: O(W)
Average Case: O(n * W)
Worst Case: O(n * W)
*/

/*
Output:
Enter the number of items: 4
Enter the weights of the items:
2 3 4 5
Enter the values of the items:
3 4 5 6
Enter the knapsack capacity: 5
The maximum value that can be obtained is: 7
*/