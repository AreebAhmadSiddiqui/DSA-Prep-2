class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0;
        string ans="";
        for(auto &ch:s){
            if(ch=='(') { 

                // only add in the answer if it is not the start of primitive string
                if(bal>0) ans+=ch; 
                bal++; 
            }
            else { 
                bal--; 
                // only add in the answer if it is not the end of primitive string
                if(bal>0) ans+=ch; 
            }
        }
        return ans;
    }
};