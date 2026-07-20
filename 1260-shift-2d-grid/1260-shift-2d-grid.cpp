class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> grid_ans(grid.size(), vector<int>(grid[0].size()));
        deque<int> process;
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[i].size(); j++) {
        //         cout << "(" << i << ", " << j << ") = " << grid[i][j] << '\n';
        //     }
        // }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                process.emplace_back(grid[i][j]);
            }
        }
         k %= process.size();
        for(int i=0;i<k;i++)
        {
            int temp = process.back();
            process.pop_back();
            process.emplace_front(temp);
        }

        

        // for(int i : process)
        // {
        //     cout<<i<<" ";
        // }
        int m = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
               grid_ans[i][j] = process[m];
               m++;
            }
        }
        return grid_ans;
    }
};