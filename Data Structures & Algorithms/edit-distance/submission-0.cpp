class Solution {
public:
    int solve(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
        if (j == b.length()) return a.length() - i;
        if (i == a.length()) return b.length() - j;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]) {
            return dp[i][j] = 0 + solve(i+1, j+1, a, b, dp);
        }

        int insert = 1 + solve(i, j+1, a, b, dp);

        int del = 1 + solve(i+1, j, a, b, dp);

        int replace = 1 + solve(i+1, j+1, a, b, dp);

        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        return solve(0, 0, word1, word2, dp);
    }
};

// insert
// delete
// replace

// want minimum of three