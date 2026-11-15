class Solution {
public:
    int n;
    
    int solve(int i, string& s, vector<int>& dp) {
        if (i == n) return 1;
        if (s[i] == '0') return 0; 
        if (dp[i] != -1) return dp[i];

        // Take 1 digit
        int single = solve(i + 1, s, dp);

        int doub = 0;
        if (i + 2 <= n && s.substr(i, 2) <= "26") {
            doub = solve(i + 2, s, dp);
        }

        return dp[i] = single + doub;
    }

    int numDecodings(string s) {
        n = s.length(); 
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
