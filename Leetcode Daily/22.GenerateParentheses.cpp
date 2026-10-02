class Solution {
public:
    void help(int open,int close,int n,string temp,vector<string> &ans){
        if(open==n){
            while(close<n){
                temp+=')';
                close++;
            }

            ans.push_back(temp);
            return;
        }

        if(open>=close){
            // I can open 

            temp+='(';
            help(open+1,close,n,temp,ans);
            temp.pop_back();

            // I can close it
            temp+=')';
            help(open,close+1,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {

        // f(o,c)

        // At any time o>=c if o<c return;

        vector<string> ans;
        string temp="(";
        help(1,0,n,temp,ans);
        return ans;
    }
};