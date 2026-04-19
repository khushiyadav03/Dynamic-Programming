class Solution {
public:
    int solve(int i, int n, string& s, vector<int>& dp){
        if(i == n) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ways = 0;

        // single digit
        ways += solve(i+1, n, s, dp);

        // two digit
        if(i+1 < n){
            int num = (s[i]-'0') * 10 + (s[i+1]-'0');
            if(num >= 10 && num <= 26) ways += solve(i+2, n, s, dp);
        }
        dp[i] = ways;
        return ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }
};