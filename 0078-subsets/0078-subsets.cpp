class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        recursion(0, temp, nums.size(),nums);
        return ans;
    }
    void recursion(int index, vector<int> temp, int n,vector<int> nums) {
        if (index >= n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        recursion(index + 1, temp, n,nums);
        temp.pop_back();
        recursion(index + 1, temp, n,nums);
    }
};