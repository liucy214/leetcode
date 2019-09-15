class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while(x) {
            // multiply overflow detection:
            // if r*10 > max, then r > max/10
            if (r > 0x7fffffff/10 || r < (int)0x80000000/10) {
                return 0;
            }
            r = r*10;
            
            // add overflow detection:
            // sign of r and d are the same
            // check sign of result and operands
            // skip check for d = zero
            int d = x%10;
            r = r+d;
            if (d && (r >> 31) != (d >> 31)) {
                return 0;
            }
      
            x = x/10;
        }
        return r;
    }
};
