class Solution {
private:
    int dp(int ind, vector<int> &nums,vector<int> &memo,int end)
    {
        if(ind > end)
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

        int pick = nums[ind] + dp(ind + 2,nums,memo,end);
        int not_pick  = 0 + dp(ind+1,nums,memo,end);

        return memo[ind] = max(pick,not_pick);

    }
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        // Case 1: Consider houses [0 ... n-2]
        vector<int> memo1(n, -1);
        int case1 = dp(0, nums, memo1, n - 2);

        // Case 2: Consider houses [1 ... n-1]
        vector<int> memo2(n, -1);
        int case2 = dp(1, nums, memo2, n - 1);

        return max(case1,case2);
    }   
};