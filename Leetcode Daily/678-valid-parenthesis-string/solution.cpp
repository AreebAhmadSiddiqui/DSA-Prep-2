class Solution {
public:
    // bool help(int i,int bal,int n,string &s,vector<vector<int>> &dp){
    //     if(i==n) return bal==0;
    //     if(bal<0) return false;

    //     if(dp[i][bal]!=-1) return dp[i][bal];

    //     bool way1=false,way2=false,way3=false;
    //     if(s[i]=='('){
    //         way1=help(i+1,bal+1,n,s,dp);
    //     }else if(s[i]==')'){
    //         way1=help(i+1,bal-1,n,s,dp);
    //     }else{
    //         // 3 choices
    //         // * -> "" , * -> '(' , 