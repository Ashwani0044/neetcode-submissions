class Solution {
public:
    int n;
    
    int solve(int i, int b, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= n) return 0;
        if (dp[i][b] != -1) return dp[i][b];
        
        int profit = 0;
        if (b == 0) {
         
            profit = max(solve(i + 1, 1, prices, dp) - prices[i], 
                         solve(i + 1, 0, prices, dp));
        } else {

            profit = max(solve(i + 2, 0, prices, dp) + prices[i], 
                         solve(i + 1, 1, prices, dp));
        }
        
        return dp[i][b] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 0, prices, dp);
    }
};
