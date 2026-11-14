class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adj(n);
        
        // Build the undirected adjacency list
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                ans++;
                
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int nei : adj[curr]) {
                        if (!vis[nei]) {
                            vis[nei] = true;
                            q.push(nei);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
