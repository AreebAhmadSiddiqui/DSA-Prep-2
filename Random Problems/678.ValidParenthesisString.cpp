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




// Greedy Way

678. Valid Parenthesis String — Greedy Revision

-   Here we maintain range of balance -> For a VPS the final balance should be zero ( bal sould be like this [low <= 0 <=high] )
-   Two important questions if high<0 at any point what does that mean??? ( till this path there is no VPS right becaues there will be zero before since high<0 low would <0 as well). So we return false here because no matter how many time we get open after it but it is not a valid VPS
-   why low=max(low,0) -> since we discard balances < 0 so we store 0 if it goes below zero
-   why? return low==0 -> from the above logic real answer could be anything but the least possible value is zero and that shoudl the VPS balance be hence this


1. What does low mean?
Minimum possible balance after processing the current prefix.
2. What does high mean?
Maximum possible balance after processing the current prefix.
3. Why can we represent all possibilities as [low, high]?
Because the possible balances always form a continuous range — there are no gaps.
4. Why are there no gaps?
Every * changes balance by -1, 0, +1, so adjacent possible balances overlap and keep the range continuous.
5. Why is storing only low/high enough?
Future operations affect every possible balance in the same way (+1, -1, or -1/0/+1). So the whole range can be propagated using its boundaries.
6. What happens with '('?
low++;
high++;

Every possible balance increases by 1.
7. What happens with ')'?
low--;
high--;

Every possible balance decreases by 1.
8. What happens with '*'?
low--;
high++;

Because * can become ')', empty, or '('.
9. Why if (high < 0) return false?
high is the best/maximum possible balance. If even that is negative, every possible path has already gone negative, so no valid path remains.
10. Why do we do low = max(0, low)?
Some paths may have gone negative, but those paths are simply invalid. If high >= 0, other valid paths may still exist.
11. Why can't a negative balance be allowed temporarily?
A valid parenthesis string can never have more closing brackets than opening brackets at any prefix.
12. Why don't we greedily choose what * means?
We don't choose one interpretation. We keep all possible interpretations compressed into [low, high].
13. What does low == 0 at the end mean?
There exists at least one valid interpretation whose final balance is exactly 0.
14. Why isn't high == 0 required?
We only need one valid interpretation. Other possibilities may finish with positive balance and that's okay.
15. Why is low == 0 sufficient at the end?
Because low represents the minimum possible balance, and the possible balances are continuous. If minimum is 0, balance 0 is achievable.
16. What if low > 0 at the end?
No interpretation can close all the opened parentheses → invalid.
17. What if low < 0 at the end?
We clamp it to 0, so this won't happen after processing each character.
18. Is this really greedy?
Not in the usual "make a choice" sense. It's more accurately DP-state compression:
many possible balances → continuous range → only store boundaries.



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
        int n=s.size();
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