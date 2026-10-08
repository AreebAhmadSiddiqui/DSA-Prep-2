class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0;
        string ans="";
        for(auto &ch:s){
            // if my balance is zero and I am starting one new primitive valid parentheses dont include it
            if(bal==0 && ch=='('){
                bal+=ch=='(' ? 1 : -1;
                continue;
            }

            
            bal+=ch=='(' ? 1 : -1;
            ans+=ch;
            // if bal becomes zero now we got the end of primitive valid parenthese so skip it as well

            if(bal==0 && ch==')'){
                ans.pop_back(); // remove the last inserted ')'
                continue;
            }
        }

        return ans;
    }
};