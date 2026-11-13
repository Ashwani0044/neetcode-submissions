class Solution {
public:
    int r, c;

    void solve(int i, int j, int& area, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i==r || j==c || grid[i][j] == 0) return;

        area++;
        grid[i][j] = 0;

        solve(i+1, j, area, grid);
        solve(i, j+1, area, grid);
        solve(i-1, j, area, grid);
        solve(i, j-1, area, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        int ans = 0;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    solve(i, j, area, grid);
                    ans = max(area, ans);
                }
            }
        }

        return ans;
    }
};