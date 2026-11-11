class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& curr) {
        if(idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        solve(idx+1, nums, curr);
        curr.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
        solve(idx+1, nums, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> curr;

        solve(0, nums, curr);

        return ans;
    }
};
