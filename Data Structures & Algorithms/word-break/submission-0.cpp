class Solution {
public:
    int n;
    int l = INT_MAX, h = INT_MIN;

    bool solve(int i, string& s, vector<string>& dict, vector<int>& dp) {
        if(i == n) return true;

        if(i > n) return false;

        if(dp[i] != -1) return dp[i];

        for(int j=l; j<=h && i+j <= n; j++) {
            string sub = s.substr(i, j);

            if(find(dict.begin(), dict.end(), sub) != dict.end()) {
                if(solve(i+j, s, dict, dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    } 

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(auto& x : wordDict) {
            l = min(l, (int)x.length());
            h = max(h, (int)x.length());
        }

        vector<int> dp(n+1, -1); 

        return solve(0, s, wordDict, dp);
    }
};
