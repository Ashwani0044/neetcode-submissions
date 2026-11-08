class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        int maxlen = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            int curr = 1;
            int n = nums[i]-1;

            while(mp.find(n) != mp.end()) {
                curr++;
                n--;
            }
            mp[nums[i]]++;
            maxlen = max(maxlen, curr);
        }

        return maxlen;
    }
};
