class Solution {
public:
    void solve(int idx, vector<int>& nums, int t, int sum, vector<int>& curr, set<vector<int>>& temp) {
        if(sum == t) {
            temp.insert(curr);
            return;
        }

        if(sum > t) return;

        for(int i=idx; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(i, nums, t, sum+nums[i], curr, temp);
            curr.pop_back();
            solve(i+1, nums,t, sum, curr, temp);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> temp;
        vector<int> curr;

        solve(0, nums, target, 0, curr, temp);

        for(auto& v : temp) ans.push_back(v);

        return ans;
    }
};
