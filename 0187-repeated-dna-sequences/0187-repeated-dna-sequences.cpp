class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};

        unordered_set<int> seen;
        unordered_set<int> repeated;
        vector<string> ans;

        auto encode = [](char c) {
            if (c == 'A') return 0;
            if (c == 'C') return 1;
            if (c == 'G') return 2;
            return 3; // T
        };

        for (int i = 0; i <= s.length() - 10; i++) {
            int code = 0;

            for (int j = i; j < i + 10; j++) {
                code = (code << 2) | encode(s[j]);
            }

            if (seen.count(code))
                repeated.insert(code);
            else
                seen.insert(code);
        }

        for (int code : repeated) {
            string dna;

            for (int i = 0; i < 10; i++) {
                int x = code & 3;

                if (x == 0) dna += 'A';
                else if (x == 1) dna += 'C';
                else if (x == 2) dna += 'G';
                else dna += 'T';

                code >>= 2;
            }

            reverse(dna.begin(), dna.end());
            ans.push_back(dna);
        }

        return ans;
    }
};