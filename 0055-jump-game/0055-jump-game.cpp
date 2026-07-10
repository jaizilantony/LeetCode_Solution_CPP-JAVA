class Solution {
    int max_val = 0;

    bool solve(vector<int> &nums,int ind)
    {
        if(max_val >= nums.size() -1)
        {
            return true;
        }

        if(ind > max_val)
        {
            return false;
        }

        max_val = max(max_val , nums[ind]+ind);
        return solve(nums,ind+1);
    }
public:
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};

