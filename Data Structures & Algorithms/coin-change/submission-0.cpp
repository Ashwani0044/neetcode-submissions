class Solution {
public:
    int n;

    int solve(int i, int t, vector<int>& coins, vector<vector<int>>& dp) {
        if (t == 0) return 0;
        if (i == n || t < 0) return INT_MAX;
        if (dp[i][t] != -1) return dp[i][t];

        int skip = solve(i + 1, t, coins, dp);

        int take = solve(i, t - coins[i], coins, dp);
        if (take != INT_MAX) {
            take += 1; 
        }

        return dp[i][t] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        
        int ans = solve(0, amount, coins, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
