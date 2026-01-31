#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement:
    Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

    The matrix contains only two possible values:
    0: A blocked cell through which the rat cannot travel.
    1: A free cell that the rat can pass through.

    Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
    If no path exists, return an empty list.

    Note: Return the final result vector in lexicographically smallest order.

*/

class Solution
{
public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    string direction = "DLRU";

    void explore(int i, int j, int &n, string curr, vector<string> &ans, vector<vector<int>> &maze)
    {
        if (i >= n || j >= n || i < 0 || j < 0)
            return;
        if (maze[i][j] == 0)
            return;
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(curr);
            return;
        }

        maze[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {

            explore(i + dx[k], j + dy[k], n, curr + direction[k], ans, maze);
        }
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here

        vector<string> ans;
        string curr = "";
        int n = maze.size();
        explore(0, 0, n, curr, ans, maze);

        return ans;
    }
};