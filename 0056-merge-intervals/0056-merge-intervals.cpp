class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() <= 1)
        {
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());

        // for(auto i : intervals)
        // {
        //     for(auto p : i)
        //     {
        //         cout<<p<<" ";
        //     }
        //     cout<<endl;
        // }
        int i = 0;
        int j = i+1;

        // while(i<intervals.size() || j<intervals.size())
        // {
        //     vector<int> temp_1 = intervals[i];
        //     vector<int> temp_2 = intervals[j];

        //     if(temp_1[1] >= temp_2[0])
        //     {
        //         ans.push_back({temp_1[0], temp_2[1]});
        //     }
        //     else
        //     {
        //         ans.push_back(temp_1);
        //         ans.push_back(temp_2);
        //     }
        //         i+=2;
        //         j = i+1;
        // }

        vector<int> temp =intervals[i];

        while(j<intervals.size())
        {
            if(temp[1] >= intervals[j][0] )
            {
                temp = {temp[0], max(temp[1], intervals[j][1])};
            }
            else
            {
                ans.push_back(temp);
                temp = intervals[j];
                i = j;
            }
            j++;
        }
        ans.push_back(temp);
        return ans;
    }
};