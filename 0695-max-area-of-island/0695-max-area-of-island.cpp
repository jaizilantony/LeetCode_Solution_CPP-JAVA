class Solution {
    int max_area = 0;

    void dfs(vector<vector<int>>& grid, int& max_length, int i, int j)
    {
        int row = grid.size();
        int col = grid[0].size();


        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0)
        {
            return;
        }


        grid[i][j] = 0;


        max_length++;

        dfs(grid, max_length, i - 1, j);
        dfs(grid, max_length, i + 1, j);
        dfs(grid, max_length, i, j - 1);
        dfs(grid, max_length, i, j + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;

                    dfs(grid, area, i, j);

                    max_area = max(max_area, area);
                }
            }
        }

        return max_area;
    }
};