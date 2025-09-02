// Problem: Rat in a Maze
// Given an n×n maze represented by a binary matrix, where 1 indicates an open cell 
// and 0 indicates a blocked cell, find all possible paths for a rat to move from 
// the top-left corner (0,0) to the bottom-right corner (n-1,n-1).
//
// The rat can move in four directions: Down (D), Left (L), Right (R), and Up (U).
// Paths must be represented as strings of these characters.
//
// Approach:
// 1. Use backtracking to explore all possible paths from the starting cell.
// 2. At each step, check boundary conditions and whether the cell is open (1).
// 3. Mark the current cell as visited (-1) to avoid cycles, then explore all directions
//    in the fixed order: Down, Left, Right, Up (D, L, R, U).
// 4. If the destination (n-1,n-1) is reached, store the current path string.
// 5. After exploring, backtrack by resetting the cell to 1.
// 6. Finally, sort all collected paths in lexicographical order for consistent output.
//
// Time Complexity: O(4^(n*n)) in the worst case (each cell explores 4 directions).
//                  Pruned significantly due to visited checks.
// Space Complexity: O(n^2) recursion + visited state stored in maze.

class Solution {
public:
    void solve(vector<vector<int>> &maze, int n, int r, int c, string path, vector<string> &ans) {
        // boundary + block check
        if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || maze[r][c] == -1) {
            return;
        }

        // destination reached
        if (r == n-1 && c == n-1) {
            ans.push_back(path);
            return;
        }

        // mark visited
        maze[r][c] = -1;

        // IMPORTANT: Explore in order D, L, R, U
        solve(maze, n, r+1, c, path + "D", ans); // Down
        solve(maze, n, r, c-1, path + "L", ans); // Left
        solve(maze, n, r, c+1, path + "R", ans); // Right
        solve(maze, n, r-1, c, path + "U", ans); // Up

        // backtrack
        maze[r][c] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze) {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans; // no path possible

        solve(maze, n, 0, 0, "", ans);

        // sort to match expected lexicographical order
        sort(ans.begin(), ans.end());

        return ans;
    }
};
