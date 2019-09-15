class Solution {
public:
    string longestPalindrome(string s) {
        // let odd, even string be odd except leading $
        string t = "$#";
        for (const auto& c : s) {
            t += c;
            t += "#";
        }
        
        vector<int> p(t.size(), 0); // radius of each pos i
        int center = 0;             // center pos of right most rb 
        int rb = 0;                 // most right barrier (rb)
        int resCenter = 0;
        int resLen = 0;
        for (int i = 1; i < t.size(); ++ i) {
            if (rb > i) {
                p[i] = min(rb-i, p[center-(i-center)]);
            } else {
                p[i] = 1;
            }
            while (t[i + p[i]] == t[i - p[i]]) {
                ++ p[i];
            }
            if (i + p[i] > rb) {
                center = i;
                rb = i + p[i];
            }
            if (p[i] > resLen) {
                resLen = p[i];
                resCenter = center;
            }
        }
        
        string r = s.substr((resCenter-resLen)/2, resLen-1);
        return r;
    }
};
