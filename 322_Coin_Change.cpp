class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, amount+1);

        dp[0]=0;

        for(int x:coins){
            for(int i=x; i<=amount; i++){
                dp[i]=min(dp[i], 1+dp[i-x]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
        
    }
};