class Solution {
public:
    int f(int amount, vector<int>& coins, vector<int>& dp){
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for(auto c : coins){
            if(amount - c >= 0){
                int res = f(amount - c, coins, dp);
                if(res != INT_MAX){
                    ans = min(ans, 1 + res);
                }
            }
        }

        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = f(amount, coins, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};