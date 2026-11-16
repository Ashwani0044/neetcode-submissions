class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = 1;
        int maxi = 1;
        int res = nums[0];

        for(auto& n : nums) {
            int tmp = maxi*n;

            maxi = max(max(n*maxi, n*mini), n);
            mini = min(min(tmp, n*mini), n);

            res = max(res, maxi);
        }

        return res;
    }
};
