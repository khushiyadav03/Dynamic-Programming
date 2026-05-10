class Solution {
public:
    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 0;

        if(i >= coins.size()) return INT_MAX;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX;

        if(amount >= coins[i]){
            int ans = solve(i, amount - coins[i], coins, dp);
            if(ans != INT_MAX) take = 1 + ans;
        }

        int notTake = solve(i+1, amount, coins, dp);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(0, amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};