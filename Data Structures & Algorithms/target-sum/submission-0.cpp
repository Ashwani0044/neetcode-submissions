class Solution {
public:
    int n;
    int offset;

    int solve(int i, int t, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) {
            return (t == 0) ? 1 : 0;
        }
        
        // Check bounds just in case target is outside [-totalSum, totalSum]
        if (t + offset < 0 || t + offset >= dp[0].size()) {
            return 0;
        }

        if (dp[i][t + offset] != -1) {
            return dp[i][t + offset];
        }

        return dp[i][t + offset] = solve(i + 1, t - nums[i], nums, dp) + 
                                   solve(i + 1, t + nums[i], nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If target is impossible to reach, return 0 immediately
        if (abs(target) > totalSum) {
            return 0;
        }

        offset = totalSum;
        // DP table size: n rows by (2 * totalSum + 1) columns
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
        
        return solve(0, target, nums, dp);
    }
};
