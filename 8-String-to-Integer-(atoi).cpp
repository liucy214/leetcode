class Solution {
public:
    int myAtoi(string str) {
        int r = 0;
        bool leading = true;
        int sign = 1;
        for (int i = 0; i < str.size(); ++ i) {
            if (leading) {
                if (str[i] == ' ') {
                    continue;
                } else if (str[i] == '+') {
                    leading = false;
                    continue;
                } else if (str[i] == '-') {
                    leading = false;
                    sign = -1;
                    continue;
                } else if (str[i] < '0' || str[i] > '9') {
                    return 0;
                } else {
                    leading = false;                   
                }
            } else {
                if (str[i] < '0' || str[i] > '9') {
                    break;
                } 
            }
            
            if (r > 0x7fffffff/10 || r < (int)0x80000000/10) {
                if (sign == 1) return 0x7fffffff;
                else return 0x80000000;
            }
            r = r*10;
            
            int d = str[i] - '0';
            if (r > (0x7fffffff - d)) {
                if (sign == 1) return 0x7fffffff;
                else return 0x80000000;
            }
            r = r+d;

        }
        return sign*r;
    }
};
