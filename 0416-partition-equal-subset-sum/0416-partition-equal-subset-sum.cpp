class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums){
            total += n;
        }

        if(total % 2 != 0) return false;

        int target = total/2;
        int n = nums.size();
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int n : nums){
            for(int t = target; t>=n; t--){
                dp[t] = dp[t] || dp[t-n];
            }
        }
        return dp[target];
    }
};