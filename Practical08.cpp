/*
Implement C++ program for solving N-Queen‟s problem using Back tracking. (Assume
N=4)
*/

#include <iostream>
#include <vector>
using namespace std;
// Function to check if a queen can be placed at a given row and column
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check the left side of the current column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
// Function to solve the N-Queens problem using backtracking
bool solveNQueens(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    {
        // All queens are successfully placed
        return true;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, N))
            {
                return true;
            }
            // If placing a queen at (row, col) doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }
    return false;
}
// Function to print the N-Queens board
void printBoard(vector<vector<int>> &board, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "Q" : ".") << " ";
        }
        cout << endl;
    }
}
int main()
{
    int N;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (solveNQueens(board, 0, N))
    {
        cout << "Solution found:" << endl;
        printBoard(board, N);
    }
    else
    {
        cout << "No solution exists for the N-Queens problem with N = " << N << "." << endl;
    }
    return 0;
}

/*
Best Case: O(N!)
Average Case: O(N!)
Worst Case: O(N!)
*/

/*
Output:
Enter the value of N for the N-Queens problem: 8
Solution found:
Q . . . . . . .
. . . . Q . . .
. . . . . . . Q
. . . . . Q . .
. . Q . . . . .
. . . . . . Q .
. Q . . . . . .
. . . Q . . . .
*/