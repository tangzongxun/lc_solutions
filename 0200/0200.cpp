class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int length = grid.size();
        int height = grid[0].size();
        int island_num = 0;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[i][j] == '1') {
                    mark(grid, i, j);
                    island_num++;
                }
            }
        }
        return island_num;
    }
    
    void mark(vector<vector<char>>& grid, int x, int y) {
        if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0) {
            return;
        }
        if (grid[x][y] != '1') {
            return;
        }
        grid[x][y] = 'x';
        mark(grid, x + 1, y);
        mark(grid, x - 1, y);
        mark(grid, x, y + 1);
        mark(grid, x, y - 1);
    }
};
