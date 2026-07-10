class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        for(int j =1;j<=numRows;++j)
        {
            vector<int> temp_2;
            temp_2 = gen_row(j);
            ans.push_back(temp_2);
        }
        return ans;
    }


    vector<int> gen_row(int val)
    {
        long long ans = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int i=1;i<val;i++)
        {
            ans = ans * (val - i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }
};