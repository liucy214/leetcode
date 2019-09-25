class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size_t count = nums.size();
        vector<int> big_num(count, 0);
        vector<vector<int>> ret;
        bool all_ones = false;
        while (!all_ones) {           
            // collect subset
            vector<int> subset;
            for(size_t i = 0; i < count; ++ i) {
                if (big_num[i]) {
                    subset.push_back(nums[i]);
                }
            }
            ret.push_back(subset);
            
            // big num ++
            long long int digit = 0;
            while (digit >= 0) {
                if (big_num[digit]) {
                    // carry in
                    big_num[digit] = 0;
                    digit++;
                    if (digit == count) {
                        // all ones
                        all_ones = true;
                        break;
                    }
                } else {
                    big_num[digit] = 1;
                    digit=-1;
                }
            }
        }
        return ret;
    }
};
