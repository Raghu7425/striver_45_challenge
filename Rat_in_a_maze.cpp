class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& maze, int n,
               vector<string>& ans, string path,
               vector<vector<int>>& vis) {
        
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // Down
        if (i + 1 < n && maze[i + 1][j] == 1 && !vis[i + 1][j]) {
            vis[i][j] = 1;
            solve(i + 1, j, maze, n, ans, path + 'D', vis);
            vis[i][j] = 0;
        }

        // Left
        if (j - 1 >= 0 && maze[i][j - 1] == 1 && !vis[i][j - 1]) {
            vis[i][j] = 1;
            solve(i, j - 1, maze, n, ans, path + 'L', vis);
            vis[i][j] = 0;
        }

        // Right
        if (j + 1 < n && maze[i][j + 1] == 1 && !vis[i][j + 1]) {
            vis[i][j] = 1;
            solve(i, j + 1, maze, n, ans, path + 'R', vis);
            vis[i][j] = 0;
        }

        // Up
        if (i - 1 >= 0 && maze[i - 1][j] == 1 && !vis[i - 1][j]) {
            vis[i][j] = 1;
            solve(i - 1, j, maze, n, ans, path + 'U', vis);
            vis[i][j] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, n, ans, "", vis);

        return ans;
    }
};