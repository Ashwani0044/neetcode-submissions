class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> s;

        for(int i=0; i<=n; i++) {
            int curr = (i == n)?0:heights[i];

            while(!s.empty() && heights[s.top()] >= curr) {
                int h = heights[s.top()];
                s.pop();

                int w = s.empty()?i:i-s.top()-1;

                ans = max(ans, h*w);
            }
            s.push(i);
        }

        return ans;

    }
};
