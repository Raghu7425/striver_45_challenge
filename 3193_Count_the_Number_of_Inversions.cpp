class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;

        vector<int> req(n, -1);
        int mx = 0;

        for (auto &r : requirements) {
            req[r[0]] = r[1];
            mx = max(mx, r[1]);
        }

        if (req[0] > 0) return 0;
        req[0] = 0;

        vector<vector<int>> dp(n, vector<int>(mx + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            int L = 0, R = mx;

            if (req[i] != -1)
                L = R = req[i];

            for (int inv = L; inv <= R; inv++) {
                long long ways = 0;

                for (int add = 0; add <= min(i, inv); add++) {
                    ways += dp[i - 1][inv - add];
                }

                dp[i][inv] = ways % MOD;
            }
        }

        return dp[n - 1][req[n - 1]];
    }
};