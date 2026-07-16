class Solution {
    vector<vector<int>> ans;
    void perm(vector<int>& nums, vector<int>& temp, vector<bool>& vis) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i =0;i<nums.size();i++)
        {
            if(vis[i])
            {
                continue;
            }
            temp.push_back(nums[i]);
            vis[i] = true;

            perm(nums,temp,vis);

            temp.pop_back();
            vis[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> vis(nums.size());
        perm(nums, temp, vis);

        return ans;
    }
};