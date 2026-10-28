class Solution {
public:
    int help(int i,int j,int xOr,int m,int n,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(i<0 || i>=m || j<0 || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return xOr^grid[i][j];

        if(dp[i][j][xOr]!=-1) return dp[i][j][xOr];

        int down=help(i+1,j,xOr^grid[i][j],m,n,grid,dp);
        int right=help(i,j+1,xOr^grid[i][j],m,n,grid,dp);

        return dp[i][j][xOr]=min(down,right);

    }
    int minCost(vector<vector<int>>& grid) {
        // general solution of max path sum ( xor ) wont work here :)
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (1025,-1)));
        return help(0,0,0,grid.size(),grid[0].size(),grid,dp);
    }
};