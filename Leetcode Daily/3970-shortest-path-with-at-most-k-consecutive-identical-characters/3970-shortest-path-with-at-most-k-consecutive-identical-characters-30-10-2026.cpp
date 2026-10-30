class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<pair<int,int>> adj[n];

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,pair<int,int>>> pq;  // {dis,{k,node}};

        vector<vector<int>> dis(n,vector<int> (k+1,1e9));

        pq.push({0,{1,0}});
        dis[0][1]=0;

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            int node=temp.second.second;
            int wt=-temp.first;
            int prevIdenticalCharCnt=temp.second.first;

            if(node==n-1) return wt;

            for(auto &it:adj[node]){
                int child=it.first;
                int edgWt=it.second;

                int newCnt= labels[node]==labels[child] ? prevIdenticalCharCnt+1 : 1;

                if(newCnt<=k && wt+edgWt<dis[child][newCnt]){
                    dis[child][newCnt]=wt+edgWt;
                    pq.push({-dis[child][newCnt],{newCnt,child}});
                }
            }
        }

        return -1;
    }
};