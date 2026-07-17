class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool is_found = false;

        for(int i =0 ;i<matrix.size();i++)
        {
            if(binary_search(matrix[i].begin(),matrix[i].end(),target))
            {
                is_found = true;
                break;
            }
        }
        return is_found;
    }
};