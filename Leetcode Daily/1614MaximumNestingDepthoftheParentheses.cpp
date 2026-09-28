1614. Maximum Nesting Depth of the Parentheses


class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        // stack<char> st;
        int stSize=0;
        for(auto &ch:s){
            if(ch=='(') {
                // st.push(ch);
                stSize++;
            }
            else if(ch==')') {
                // maxi=max(maxi,st.size());
                maxi=max(maxi,stSize);
                // st.pop();
                stSize--;
            }
        }
        return maxi;
    }
};