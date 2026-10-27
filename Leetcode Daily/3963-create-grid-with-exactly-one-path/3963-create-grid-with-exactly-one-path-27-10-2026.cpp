class Solution {
public:
    vector<string> createGrid(int m, int n){
        vector<string> ans;
        for(int i=0;i<m;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+='#';
            }
            ans.push_back(temp);
        }

        // traverse bottom till the end and then right till the target
        for(int i=0;i<m;i++) ans[i][0]='.';
        for(int j=0;j<n;j++) ans[m-1][j]='.';
        
        return ans;
    }
};