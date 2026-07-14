class Solution {
    // int global_max =0;
public:
    int maximum69Number (int num) {
        int global_max = num;
        string num_var = to_string(num);
        for(int i =0;i<num_var.length();++i)
        {
            if(num_var[i] =='6')
            {
                num_var[i]='9';
               int temp =  stoi(num_var);
                if(temp > global_max)
                {
                    global_max = temp;
                }
                num_var[i] = '6';
            }
        }
        return global_max;
    }
};