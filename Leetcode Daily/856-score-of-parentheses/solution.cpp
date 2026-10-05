class Solution {
public:
    int scoreOfParentheses(string s) {
        // think of depth it will help

        // (((()())))

        // we are concerned only on the lowest dept valid parenthese
        // int his case what will be the case 2*2*2*1 for first one and similary 2*2*2*1 for the second one after that do you need to do anything no let them pop because u already multiplied all the 2s
        // so basically we are going from top down not bottom up

        // // One question when to add and when to multiply

        // ))) no matter what this need multiplying

        // () this needs adding to our answer

        // Thats it

        int ans=0;
        stack<char> st;
        char prev='a';
        for(auto &ch:s){
            if(ch=='(') st.push('(');
            else{

                // check if previous is open or close
                // if open then add to the answer if close then multiply
                // What to add??? ((())) what will u add here 2*2*1 -> 2^(st.size()-1)
                if(prev=='(') ans+=pow(2,st.size()-1);
                else{
                    // we have already taken care of the multiplication
                }

                st.pop();
            }
            prev=ch;
        }

        return ans;
    }
};