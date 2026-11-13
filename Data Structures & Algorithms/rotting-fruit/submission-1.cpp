class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int ans = 0;
        
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int sz = q.size();
            bool rottedThisMinute = false;

            // Process all rotten oranges for the current minute
            for (int k = 0; k < sz; k++) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                        rottedThisMinute = true;
                    }
                }
            }

            if (rottedThisMinute) {
                ans++;
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
