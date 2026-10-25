class Solution {
public:
    bool isValid(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis){
        return r<grid.size() && c<grid[0].size() && r>=0 && c>=0;
    }
    bool dfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        if(!isValid(row,col,grid,vis)) return false;
        if(grid[row][col]==1 || vis[row][col]) return true;

        vis[row][col]=1;
        
        bool isSurrounded=true;

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        for(int del=0;del<4;del++){
            int newRow=row+dx[del];
            int newCol=col+dy[del];

            if(!dfs(newRow,newCol,grid,vis)){
                isSurrounded=false;
            }
        }

        return isSurrounded;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();


        // I will dfs from every zero
        // if the dfs path returns true everytime i will add this to one of my group


        vector<vector<int>> vis(m,vector<int> (n,0));

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    if(dfs(i,j,grid,vis)) cnt++;
                }
            }
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }

        return cnt;
    }
};