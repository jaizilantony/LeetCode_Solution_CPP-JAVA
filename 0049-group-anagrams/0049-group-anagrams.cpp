class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort(strs.begin(), strs.end());
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ans;

        // for (const auto& row : strs) {
        //     for (const auto& x : row) {
        //         cout << x << " ";
        //     }
        //     cout << '\n';
        // }

        for (const auto& x : strs) {
            string temp = x;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(x);
        }
    


        for (auto& it : mpp) {
            ans.push_back(it.second);
            // for(string a : it.second)
            // {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
        }

        sort(ans.begin(),ans.end(),[](const vector<string> &a,const vector<string> &b){
            return a.size() < b.size();
        });

        return ans;
    }
};
