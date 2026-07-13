class Solution {
    int count = 0;

    void solve(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] =='0')
        {
            return;
        }
        grid[i][j] = '0';
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j-1,grid);
        solve(i,j+1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(grid[i][j] == '1'){
                count++;
                solve(i,j,grid);
                }
            }
        }
        return count;
    }
};