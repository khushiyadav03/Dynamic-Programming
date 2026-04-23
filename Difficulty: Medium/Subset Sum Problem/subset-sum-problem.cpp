class Solution {
  public:
    bool solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i < 0) return false;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool notTake = solve(i-1, target, arr, dp);
        
        bool take = false;
        if(arr[i] <= target) take = solve(i-1, target - arr[i], arr, dp);
        
        return dp[i][target] = take || notTake;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(n-1, sum, arr, dp);
    }
};