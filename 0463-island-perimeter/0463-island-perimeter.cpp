class Solution {
    int peri = 0;

    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1)
            return;

        grid[i][j] = 2;    

        int temp_peri = 4;

        if(i > 0 && grid[i-1][j] != 0)
            temp_peri--;

        if(i + 1 < grid.size() && grid[i+1][j] != 0)
            temp_peri--;

        if(j > 0 && grid[i][j-1] != 0)
            temp_peri--;

        if(j + 1 < grid[0].size() && grid[i][j+1] != 0)
            temp_peri--;

        peri += temp_peri;

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid);
                }
            }
        }
        return peri;
    }
};