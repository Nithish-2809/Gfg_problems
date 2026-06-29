class Solution {
public:
    void solve(int row, int col,
               vector<vector<int>>& maze,
               vector<vector<int>>& visited,
               vector<string>& ans,
               string &path,
               int n) {

        // Reached destination
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[row][col] = 1;

        // Down
        if (row + 1 < n &&
            maze[row + 1][col] == 1 &&
            !visited[row + 1][col]) {

            path.push_back('D');
            solve(row + 1, col, maze, visited, ans, path, n);
            path.pop_back();
        }

        // Left
        if (col - 1 >= 0 &&
            maze[row][col - 1] == 1 &&
            !visited[row][col - 1]) {

            path.push_back('L');
            solve(row, col - 1, maze, visited, ans, path, n);
            path.pop_back();
        }

        // Right
        if (col + 1 < n &&
            maze[row][col + 1] == 1 &&
            !visited[row][col + 1]) {

            path.push_back('R');
            solve(row, col + 1, maze, visited, ans, path, n);
            path.pop_back();
        }

        // Up
        if (row - 1 >= 0 &&
            maze[row - 1][col] == 1 &&
            !visited[row - 1][col]) {

            path.push_back('U');
            solve(row - 1, col, maze, visited, ans, path, n);
            path.pop_back();
        }

        visited[row][col] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();

        vector<string> ans;

        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";

        solve(0, 0, maze, visited, ans, path, n);

        return ans;
    }
};