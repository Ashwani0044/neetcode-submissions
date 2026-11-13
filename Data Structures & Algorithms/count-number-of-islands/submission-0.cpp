class Solution {
public:
    void sinkIsland(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';

        sinkIsland(grid, r - 1, c, rows, cols); 
        sinkIsland(grid, r + 1, c, rows, cols); 
        sinkIsland(grid, r, c - 1, rows, cols);
        sinkIsland(grid, r, c + 1, rows, cols); 
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int r = grid.size();
        int c = grid[0].size();
        int res = 0;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '1') {
                    res++;

                    sinkIsland(grid, i, j, r, c);
                }
            }
        }

        return res;
    }
};