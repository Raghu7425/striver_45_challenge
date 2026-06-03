class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=nums[0];
        int maxsum = nums[0];
        for(int i=1; i<nums.size(); i++){
                

                if(currSum <  0){
                    currSum = 0;
                }
                currSum+=nums[i];
                maxsum = max(currSum, maxsum);
        }
        return maxsum;
    }
};