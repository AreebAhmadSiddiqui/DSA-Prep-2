32. Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1); // boundary starts
        int ans = 0;
        // stack stores boundary for our valid answers
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }
            else {

                st.pop();

                if(st.empty()) {
                    st.push(i); // start a new boundary here
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};