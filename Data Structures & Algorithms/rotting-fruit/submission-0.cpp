class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;

        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            bool cool = false;

            if(i+1 < r && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q.push({i+1, j});
                cool = true;
                fresh--;
            }
            if(j+1 < c && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q.push({i, j+1});
                cool = true;
                fresh--;
            }
            if(i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q.push({i-1, j});
                cool = true;
                fresh--;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q.push({i, j-1});
                cool = true;
                fresh--;
            }

            if(cool) ans++;  
        }

        return fresh==0?ans:-1;
    }
};
