class Solution {
public:
    int n;

    int solve(int i, int t, vector<int>& coins, vector<vector<int>>& dp) {
        if(i == n || t < 0) return 0;

        if(t == 0) return 1;

        if(dp[i][t] != -1) return dp[i][t];

        // take it again
        int x = solve(i, t-coins[i], coins, dp);

        // skip it
        int z = solve(i+1, t, coins, dp);

        return dp[i][t] = x + z;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return solve(0, amount, coins, dp);
    }
};
