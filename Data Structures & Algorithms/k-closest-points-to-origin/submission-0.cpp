class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;
        
        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            pq.push({x * x + y * y, i});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [d, idx] = pq.top(); 
            pq.pop();
            ans.push_back(points[idx]);
        }

        return ans;
    }
};
