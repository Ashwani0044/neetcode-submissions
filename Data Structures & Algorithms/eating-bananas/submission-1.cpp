class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r) {
            int mid = l+(r-l)/2;

            long long x = 0;

            for(auto& p:piles) {
                x += (p+mid-1)/mid;
            }

            if(x <= h) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ans;
    }
};

// the max can be the maximum number 
// the min can be 1
// we need to find the min k that is within h
