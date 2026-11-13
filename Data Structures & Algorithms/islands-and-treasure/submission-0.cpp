#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) return;
        int c = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nextR = currR + d[0];
                int nextC = currC + d[1];
                
                if (nextR >= 0 && nextR < r && nextC >= 0 && nextC < c && grid[nextR][nextC] == 2147483647) {
                    grid[nextR][nextC] = grid[currR][currC] + 1;
                    q.push({nextR, nextC});
                }
            }
        }
    }
};
