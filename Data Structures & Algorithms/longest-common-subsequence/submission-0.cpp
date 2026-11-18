class Solution {
public:
    int l1, l2;

    int solve(int i, int j, string& t1, string& t2, vector<vector<int>>& dp) {

        if(i == l1 || j == l2) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int eq = 0;
        if(t1[i] == t2[j]) {
            eq = 1 + solve(i+1, j+1, t1, t2, dp);
        }

        return dp[i][j] = max({eq, solve(i+1, j, t1, t2, dp), solve(i, j+1, t1, t2, dp)});

    }

    int longestCommonSubsequence(string text1, string text2) {
        l1 = text1.length();
        l2 = text2.length();

        vector<vector<int>> dp(l1, vector<int>(l2, -1));

        return solve(0, 0, text1, text2, dp); 
    }
};
