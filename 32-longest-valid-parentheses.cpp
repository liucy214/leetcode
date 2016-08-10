#include <stack>
#include <iostream>

using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // -1: (, -2: )
        int maxP = 0;

        // init
        st.push(0);

        for(auto c: s) {
            if (c == '(') {
                st.push(-1);
            } else { // ')'
                int tmp = 0;
                while(1) {
                    int t = st.top();
                    st.pop();
                    if (t == -1) { // '('
                        tmp++;
                        while(!st.empty() && st.top() != -1 && st.top() != -2) {
                            tmp += st.top();
                            st.pop();
                        }
                        st.push(tmp);
                        break;
                    } else if (t == -2) { // ')'
                        st.push(t);
                        st.push(tmp);
                        st.push(-2);
                        break;
                    } else { // num
                        tmp += t;
                        if (st.empty()) {
                            st.push(tmp);
                            st.push(-2);
                            break;
                        }
                    }
                }
                maxP = maxP < tmp ? tmp : maxP;
            }
        }
        return maxP*2;
    }
};

int main(int argc, const char* argv[]) {
    string in = "()()(()(()())";
    Solution s;
    cout << in << ", len: " << s.longestValidParentheses(in) << endl;
    return 0;
}

