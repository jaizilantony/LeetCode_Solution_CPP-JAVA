// class Solution {
//     vector<vector<int>> ans;
//     vector<int> temp;
//     set<vector<int>> hs;

//     void solve(vector<int>& candidates, int target,vector<int> &temp,set<vector<int>> &hs)
//     {
//         if(target == 0)
//         {
//             // sort(temp.begin(),temp.end());
//            // if(!hs.contains(temp))
//            // {
//                 //hs.insert(temp);
//                 ans.push_back(temp);
//                 // cout<<target;
//                 // for(int i : temp)
//                 // {
//                 //     cout<<i<<" ";
//                 // }
//                 // cout<<endl;
//             //}
//             return;
//         }

//         if(target < 0)
//         {
//             return;
//         }
//         for(int i : candidates)
//         {
//             temp.push_back(i);
//             solve(candidates,target - i,temp,hs);
//             temp.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         solve(candidates,target,temp,hs);
//         return ans;
//     }
// };


class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    set<vector<int>> hs;

    void solve(vector<int>& candidates, int target,
               vector<int>& temp, set<vector<int>>& hs) {
        if (target == 0) {
            vector<int> curr = temp;
            sort(curr.begin(), curr.end());

            if (hs.find(curr) == hs.end()) {
                hs.insert(curr);
                ans.push_back(curr);
            }
            return;
        }

        if (target < 0)
            return;

        for (int x : candidates) {
            temp.push_back(x);
            solve(candidates, target - x, temp, hs);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, temp, hs);
        return ans;
    }
};