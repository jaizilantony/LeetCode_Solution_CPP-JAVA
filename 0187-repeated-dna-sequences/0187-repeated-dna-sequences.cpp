class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mpp;
        vector<string> ans;

        if(s.length() < 10){return {};}

        for(int i =0;i<=(s.length()-10);i++)
        {
            string temp = s.substr(i,10);
            mpp[temp]++;
        }

        for(const auto &p : mpp)
        {
            if(p.second >1)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};