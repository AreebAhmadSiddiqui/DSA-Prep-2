class Solution {
public: 
    int mod=1e9+7;
    int help(int row,int col,int prevMove,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(row<0 || row>=n || col<0 || col>=m ) return 0;
        if(row==n-1 && col==m-1){
            return 1;
        }

        if(dp[row][col][prevMove]!=-1) return dp[row][col][prevMove];


        int currCellValue=grid[row][col];
        int right=0,down=0;
        if(currCellValue==0){
            
            // right
            // temp.push_back('R');
            right=help(row,col+1,1,n,m,grid,dp);
            // temp.pop_back();


            // down
            // temp.push_back('D');
            down=help(row+1,col,0,n,m,grid,dp);
            // temp.pop_back();

        }else{

            // Now I have to mirror

            if(prevMove==1){ // right
                
                // go down
                // temp.push_back('D');
                down=help(row+1,col,0,n,m,grid,dp);
                // temp.pop_back();
            }else{ // prevmove was down

                // go right
                // temp.push_back('R');
                right=help(row,col+1,1,n,m,grid,dp);
                // temp.pop_back();
            }
        }

        return dp[row][col][prevMove]=(right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // I am thinking of adding one extra boolean var to tell which path I took last (right or down) ( rigth will be 1 and down would be 0)

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (2,-1)));
        return help(0,0,0,n,m,grid,dp);
    }
};
