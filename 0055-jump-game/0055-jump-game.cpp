class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If current index is beyond our maximum reachable index
            if (i > maxReach)
                return false;

            // Update the furthest reachable index
            maxReach = max(maxReach, i + nums[i]);

            // If we can already reach or pass the last index
            if (maxReach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int max_val = 0;
//         bool ans = false;
//         for(int i : nums)
//         {
//             if(i > max_val)
//             {
//                 max_val = i;
//             }
//             if (i<max_val)
//             {
//                 ans = false;
//             }
//             if(max_val > nums.size())
//             {
//                 ans = true;
//             }
//         }
//         return ans;
//     }
// };