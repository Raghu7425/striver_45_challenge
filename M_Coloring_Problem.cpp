class Solution {
public:
    bool isSafe(int node, int color, vector<int>& colors,
                vector<vector<int>>& adj) {
        for (int neigh : adj[node]) {
            if (colors[neigh] == color)
                return false;
        }
        return true;
    }

    bool solve(int node, int v, int m,
               vector<int>& colors,
               vector<vector<int>>& adj) {
        if (node == v)
            return true;

        for (int color = 1; color <= m; color++) {
            if (isSafe(node, color, colors, adj)) {
                colors[node] = color;

                if (solve(node + 1, v, m, colors, adj))
                    return true;

                colors[node] = 0; // backtrack
            }
        }
        return false;
    }

    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);

        for (auto &e : edges) {
            int u = e[0];
            int w = e[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<int> colors(v, 0);

        return solve(0, v, m, colors, adj);
    }
};