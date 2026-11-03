class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        // vector<int> given(n);
        // for(int i =1;i<=n;i++)
        // {
        //     given[i-1] = i; 
        // }
        vector<int> temp; 
        recursive(1,temp,k,n);
        return ans;
    }
    void recursive(int i,vector<int> temp,int k,int n)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }

        for(int start = i;start<=n;start++)
        {
            temp.push_back(start);
            recursive(start+1,temp,k,n);
            temp.pop_back();
        }
    }
};