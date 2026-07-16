class Solution {
private:
    int dp(int ind, vector<int> &nums,vector<int> &memo)
    {
        if(ind >= nums.size())
        {
            return 0;
        }
        // if(ind>0)
        // {
        //     return 0;
        // }
        if(memo[ind] != -1)
        {
            return memo[ind];
        }

        int pick = nums[ind] + dp(ind + 2,nums,memo);
        int not_pick  = 0 + dp(ind+1,nums,memo);

        return memo[ind] = max(pick,not_pick);

    }
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();

        vector<int> memo(n,-1);

        return dp(0,nums,memo);
    }   
};