class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        string work;
        for (auto c : s) {
            auto it = work.find(c);
            if (it != std::string::npos) {
                if (work.size() > len) {
                    len = work.size();
                }
                work = work.substr(it+1);                
            }
            work += c;
        }
        if (work.size() > len) {
            len = work.size();
        }
        return len;
    }
};
