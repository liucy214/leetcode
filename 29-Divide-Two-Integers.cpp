class Solution {
public:
    int divide_pos(int v, int d)
    {
        if (v < d) return 0;
        int q = 0;
        int d2 = d;
        int q2 = 1;
        while( v >= d) {
            int d3 = d2 << 1;
            int overflow = d3 <= 0;
            while(!overflow && v >= d3) { 
                d2 <<= 1;
                q2 <<= 1;
                d3 = d2 << 1;
                overflow = d3 <= 0;
            }
            v -= d2;
            q += q2;
            d2 = d;
            q2 = 1;
        }
        return q;
    }
    
    int divide_neg(int v, int d)
    {
        if (v > d) return 0;
        int q = 0;
        int d2 = -d;
        int q2 = 1;
        while( v <= d) {
            int d3 = (d2 << 1);
            int overflow = d3 <= 0;
            while(!overflow && v <= -d3) { 
                d2 <<= 1;
                q2 <<= 1;
                d3 = (d2 << 1);
                overflow = d3 <= 0;                
            }
            v -= -d2;
            q += q2;
            d2 = -d;
            q2 = 1;
        }
        return q;
    }
        
    int divide(int dividend, int divisor) {
        int sign = ((dividend >= 0) ^ (divisor >= 0)) ? -1 : 1;
        int q = 0;
        int v = dividend;
        int d = divisor;              
        if (v >= 0 && d > 0) {
            // v >= 0 and d > 0
            q = divide_pos(v, d);
        } else if (v <= 0 && d < 0) {
            if (v == d) return 1;
            else if (d == 0x80000000) return 0;
            else if (d == -1 && v == 0x80000000) return 0x7fffffff;
            // v <= 0 and d < 0
            q = divide_neg(v, d);
        } else if (v >= 0 && d < 0) {
            if (d == 0x80000000) return 0;
            d = -d;
            // v >= 0 and d > 0
            q = divide_pos(v, d);
        } else if (v <= 0 && d > 0) {
            if (v == 0x80000000 && d == 1) return v;
            d = -d;
            // v <= 0 and d < 0
            q = divide_neg(v, d);
        }
        return sign*q;
    }
};
