#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

static bool compare(const int& a, const int& b) {
    stringstream ssab;
    stringstream ssba;
    ssab << a << b;
    ssba << b << a;
    long long int ab;
    long long int ba;
    ssab >> ab;
    ssba >> ba;
    return ab > ba;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        stringstream ss;
        sort(nums.begin(), nums.end(), compare);
        if (!nums.empty() && nums[0] != 0) {
            for(auto n: nums) {
                ss << n;
            }
        } else {
            return "0";
        }
        return ss.str();
    }
};

int main(int argc, const char* argv[]){
    vector<int> nums = {824,938,1399,5607,6973,5703,9609,4398,8247};
    Solution s;
    cout << s.largestNumber(nums);

    return 0;
}
