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
    //         // * -> "" , * -> '(' , * -> ')'
    //         way3=help(i+1,bal,n,s,dp) || help(i+1,bal+1,n,s,dp) || help(i+1,bal-1,n,s,dp);
    //     }

    //     return dp[i][bal]=way1 || way2 || way3;

    // }
    bool checkValidString(string s) {
        
        // Check all ways
        int n=s.size(); ///test
        // vector<vector<int>> dp(n+1,vector<int> (n+2,0)); // dp[i][balance] -> balance +1 if '(' else -1 if anytime < 0 return false;

        // return help(0,0,n,s,dp);

        // // TABULATION

        // dp[n][0]=1;

        // for(int i=n-1;i>=0;i--){
        //     for(int bal=n;bal>=0;bal--){
        //         bool way1=false,way2=false,way3=false;
        //         if(s[i]=='('){
        //             way1=dp[i+1][bal+1];
        //         }else if(s[i]==')'){
        //             way1=bal-1>=0 ? dp[i+1][bal-1] : false;
        //         }else{
        //             // 3 choices
        //             // * -> "" , * -> '(' , * -> ')'
        //             way3=dp[i+1][bal] || dp[i+1][bal+1] || (bal-1>=0 ? dp[i+1][bal-1] : false);
        //         }

        //         dp[i][bal]=way1 || way2 || way3;
        //     }
        // }

        // return dp[0][0];

        // Space optimized

        // vector<int> curr(n+2,0),next(n+2,0);

        // next[0]=1;

        // for(int i=n-1;i>=0;i--){
        //     for(int bal=n;bal>=0;bal--){
        //         bool way1=false,way2=false,way3=false;
        //         if(s[i]=='('){
        //             way1=next[bal+1];
        //         }else if(s[i]==')'){
        //             way1=bal-1>=0 ? next[bal-1] : false;
        //         }else{
        //             // 3 choices
        //             // * -> "" , * -> '(' , * -> ')'
        //             way3=next[bal] || next[bal+1] || (bal-1>=0 ? next[bal-1] : false);
        //         }

        //         curr[bal]=way1 || way2 || way3;
        //     }
        //     next=curr;
        // }

        // return curr[0];


        // Optimal
        // Maintain ranges of the balance

        int low=0,high=0;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                // it will increase for every balance
                low++;
                high++;
            }else if(s[i]==')'){
                // it will decrease for every balance
                low--;
                high--;
            }else{
                // new addition would be {-1,0,+1};

                // loweest would be low-1 and highest would be high+1;

                low-=1;
                high+=1;
            }

            // if any moment high<0 not a valid VPS till here so dont check for the rest
            if(high<0) return false;
            low=max(low,0); // to protect from going -ve; ( Our valid ranges is positive only right????) 
        }

        return low==0;
    }
};