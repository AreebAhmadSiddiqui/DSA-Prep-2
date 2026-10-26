class Solution {
public:
    bool isValid(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        return row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !vis[row][col] && grid[row][col]!=0;
    }
    long long bfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis){
        queue<pair<int,int>> q;

        long long sum=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            sum+=grid[row][col];

            for(int i=0;i<4;i++){
                int newRow=row+dx[i];
                int newCol=col+dy[i];

                if(isValid(newRow,newCol,grid,vis)){
                    q.push({newRow,newCol});
                    vis[newRow][newCol]=1;
                }
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));

        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    cnt+=bfs(i,j,grid,vis)%k==0;
                }
            }
        }
        return cnt;
    }
};