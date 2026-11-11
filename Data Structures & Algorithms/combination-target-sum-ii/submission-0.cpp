class Solution {
public:
    void solve(int i, vector<int>& nums, int t, int sum, vector<int>& curr, vector<vector<int>>& temp) {
        if(sum == t) {
            temp.push_back(curr);
            return;
        }

        if(sum > t || i >= nums.size()) return;

    
        curr.push_back(nums[i]);
        solve(i+1, nums, t, sum+nums[i], curr, temp);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        solve(i+1, nums,t, sum, curr, temp);
    
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, 0, curr, temp);

        return temp;
    }
};
