class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;

        if (nums.empty()) {
            return ret;
        }

        // sort, i.e. [1, 2, 2, 3, 3, 3]
        std::sort(nums.begin(), nums.end());
        
        // scan the sorted numbers to get a vector with
        // unique number and repeat counts
        vector<tuple<int, int>> nums_t;
        int prev = nums[0];
        size_t count = 1;
        int curr = prev;
        size_t i = 1;
        while (i < nums.size()) {
            curr = nums[i];
            if (curr == prev) {
                ++count;
            } else {
                std::tuple<int, int> t = std::make_tuple(prev, count);
                nums_t.push_back(t);
                
                prev = curr;
                count = 1;
            }
            ++i;
        }
        // last one
        std::tuple<int, int> t = std::make_tuple(curr, count);
        nums_t.push_back(t);

        // get all subset by repeating adding big number by 1
        vector<int> big_num(nums_t.size(), 0);
        bool all_ones = false;
        while(!all_ones) {
            // record a subset
            vector<int> subset;
            for (size_t i=0; i<big_num.size(); ++i) {
                for(int c=0; c<big_num[i]; ++c) {
                    subset.push_back(std::get<0>(nums_t[i]));
                }
            }
            ret.push_back(subset);
            
            // add one
            size_t digit = 0;
            while (true) {
                int count = std::get<1>(nums_t[digit]);
                if (big_num[digit] == count) {
                    // carry in
                    big_num[digit] = 0;
                    ++ digit;
                    if (digit == nums_t.size()) {
                        all_ones = true;
                        break;
                    }
                } else {
                    ++big_num[digit];
                    break;
                }
            }
        }
        return ret;
    }
};
