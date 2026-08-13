// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         // int left_sum = 0;
//         // int right_sum = 0;
//         // int prefix_sum = 0;
//         // int sum = 0;
//         // int index = 0;    
//         // for(int i : nums)
//         // {
//         //     prefix_sum += i;
//         // }

//         // // cout <<prefix_sum;
//         // map<int, int> mpp;
//         // mpp[0] = -1;
//         // for (int i = 0; i < nums.size(); i++) {
//         //     sum += nums[i];

//         //     if (!mpp.contains(sum)) {
//         //         mpp[sum] = i;
//         //     } 
//         //     // else {
//         //     //     auto iter = mpp.find(sum);
//         //     //     cout << (i - iter->second) << endl;
//         //     // }
//         // }
            
//         //     for(const auto&p : mpp)
//         //     {
//         //         cout<<p.first<<" : "<<p.second;
//         //         cout<<endl;
//         //     }
//         //     cout<<"map diff values"<<endl;
//         //     for(const auto&p : mpp)
//         //     {
//         //         if(p.second == -1)
//         //         {
//         //             continue;
//         //         }
//         //         int diff = prefix_sum - p.first;
//         //         cout << diff<< endl;
//         //         if(mpp.contains(diff) && diff != prefix_sum && diff != 0)
//         //         {
//         //             index = p.second;
//         //         }
//         //     }

//         //     return index;

        
//     }
// };


class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = 0;

        for (int x : nums) {
            total += x;
        }

        int left = 0;

        for (int i = 0; i < nums.size(); i++) {

            int right = total - left - nums[i];

            if (left == right) {
                return i;
            }

            left += nums[i];
        }

        return -1;
    }
};