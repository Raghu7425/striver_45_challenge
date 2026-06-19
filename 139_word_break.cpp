class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto &w : wordDict)
            maxLen = max(maxLen, (int)w.size());

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= maxLen && len <= i; len++) {
                if (dp[i - len] &&
                    st.count(s.substr(i - len, len))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};