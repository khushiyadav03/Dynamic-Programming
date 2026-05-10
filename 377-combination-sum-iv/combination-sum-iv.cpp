class Solution {
public:
    int solve(int i, int target, vector<int>& nums, vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(i >= nums.size()) return 0;

        if(dp[target] != -1) return dp[target];

        int take = solve(0, target - nums[i], nums, dp);
        int notTake = solve(i+1, target, nums, dp);

        return dp[target] = take + notTake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(0, target, nums, dp);
    }
};