class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};

        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> ans;

        for (int i = 0; i <= s.length() - 10; i++) {
            string temp = s.substr(i, 10);

            if (seen.count(temp)) {
                repeated.insert(temp);
            } else {
                seen.insert(temp);
            }
        }

        for (const string& str : repeated) {
            ans.push_back(str);
        }

        return ans;
    }
};