678. Valid Parenthesis String

// Memoization

class Solution {
public:
    bool help(int i,int bal,int n,string &s,vector<vector<int>> &dp){
        if(i==n) return bal==0;
        if(bal<0) return false;

        if(dp[i][bal]!=-1) return dp[i][bal];

        bool way1=false,way2=false,way3=false;
        if(s[i]=='('){
            way1=help(i+1,bal+1,n,s,dp);
        }else if(s[i]==')'){
            way1=help(i+1,bal-1,n,s,dp);
        }else{
            // 3 choices
            // * -> "" , * -> '(' , * -> ')'
            way3=help(i+1,bal,n,s,dp) || help(i+1,bal+1,n,s,dp) || help(i+1,bal-1,n,s,dp);
        }

        return dp[i][bal]=way1 || way2 || way3;

    }
    bool checkValidString(string s) {
        
        // Check all ways
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1)); // dp[i][balance] -> balance +1 if '(' else -1 if anytime < 0 return false;

        return help(0,0,n,s,dp);
    }
};