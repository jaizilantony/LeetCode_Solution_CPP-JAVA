class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        prefixsum.resize(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), prefixsum.begin() + 1);
    }
    
    int sumRange(int left, int right) {
        return prefixsum[right+1] - prefixsum[left];
    }   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */