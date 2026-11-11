class Solution {
public:
    void solve(int i, vector<int>& nums, int t, int sum, vector<int>& curr, vector<vector<int>>& temp) {
        if(sum == t) {
            temp.push_back(curr);
            return;
        }

        if(sum > t || i >= nums.size()) return;

    
        curr.push_back(nums[i]);
        solve(i, nums, t, sum+nums[i], curr, temp);
        curr.pop_back();
        solve(i+1, nums,t, sum, curr, temp);
    
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> temp;
        vector<int> curr;

        solve(0, nums, target, 0, curr, temp);

        return temp;
    }
};
