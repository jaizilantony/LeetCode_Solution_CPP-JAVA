class Solution {
    int total_count = 0;

    void can(int i, string &s)
    {
        total_count++;

        for (int k = i; k < i + 3 && k < s.length(); ++k)
        {
            s[k] = 'O';
        }
    }

public:
    int minimumMoves(string s) {
        int i = 0;

        while (i < s.length())
        {
            if (s[i] == 'X')
            {
                can(i, s);
                i += 3;        
            }
            else
            {
                i++;
            }
        }

        return total_count;
    }
};