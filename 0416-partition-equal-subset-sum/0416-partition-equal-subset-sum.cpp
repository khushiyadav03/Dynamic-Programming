class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i<0) return false;
        
        if(dp[i][target] != -1) return dp[i][target];

        bool notTake = solve(i-1, target, nums, dp);
        bool take = false;
        if(nums[i] <= target){
            take = solve(i-1, target-nums[i], nums, dp);
        }
        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int n : nums){
            total += n;
        }

        if(total % 2 != 0) return false;

        int target = total/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(n-1, target, nums, dp);
    }
};