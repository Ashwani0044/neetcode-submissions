class Solution {
public:
    int n;

    int solve(int i, int p, vector<int>& nums, vector<vector<int>>& dp) {
        if(i >= n) return 0;

        if(dp[i][p+1] != -1) return dp[i][p+1];

        int take = 0;
        if(p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(i+1, i, nums, dp);
        }

        int skip = 0 + solve(i+1, p, nums, dp);

        return dp[i][p+1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, -1, nums, dp);
    }
};
