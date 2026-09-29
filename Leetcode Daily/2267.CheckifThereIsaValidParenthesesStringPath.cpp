2267. Check if There Is a Valid Parentheses String Path

class Solution {
public:
    bool help(int i, int j, int m,int n,vector<vector<char>>&grid,int balance,vector<vector<vector<int>>> &dp) {
        if(i>=m || j>=n) return false;

        balance+=grid[i][j]=='(' ? 1 : -1;

        if(balance<0) return false;

        if(i==m-1 && j==n-1) return balance==0;

        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        
        bool down = help(i+1,j,m,n,grid,balance,dp);
        bool right = help(i,j+1,m,n,grid,balance,dp);

        return dp[i][j][balance]=down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // max moves will be m+n-1
        // Also we are just calculting no of opening - no of closing brackets if it is equal to zero then fine
        // Also keep in mind that we add + 1 for '(' and -1 for ')' so it ensures we take care of any () valid brackets in between

        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int> (m+n+2,0)));
        dp[m-1][n-1][0]=1;
        // Tabulation

        // This I copied an edge case

        if ((m + n - 1) % 2) return false;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                for(int balance=m+n;balance>=0;balance--){
                        
                        int newBalance=balance;
                        newBalance+=grid[i][j]=='(' ? 1 : -1;

                        if(newBalance<0) continue;
                        // Destination
                        if (i==m-1 && j==n-1) {
                            dp[i][j][balance] = (newBalance == 0);
                            continue;
                        }

                        
                        bool down = dp[i+1][j][newBalance];
                        bool right = dp[i][j+1][newBalance];

                        dp[i][j][balance]=down || right;
                }
            }
        }


        int ans=dp[0][0][0];
        return ans==-1 ? 0 : ans;
    }
};