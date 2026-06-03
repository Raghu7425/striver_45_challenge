class Soltuion{
    void buy_and_sell(vector<int>&nums){
        int bestbuy=nums[0];
        int maxprofit = 0;

        for(int i=1; i<nums.end(); i++){
            bestbuy = min(bestbuy, nums[i]);
            maxprofit = max(maxprofit, nums[i]-bestbuy);
        }
        return maxprofit;
    }
};