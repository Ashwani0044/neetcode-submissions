class Solution {
public:
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }


        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                dfs(i, indegree, adj);
            }
        }

        if(ans.size() != numCourses) return {};

        return ans;
        
    }

    void dfs(int n, vector<int>& indegree, vector<vector<int>>& adj) {
        ans.push_back(n);
        indegree[n]--;

        for(int nei : adj[n]) {
            indegree[nei]--;
            if(indegree[nei] == 0) {
                dfs(nei, indegree, adj);
            }
        }
    }
};
