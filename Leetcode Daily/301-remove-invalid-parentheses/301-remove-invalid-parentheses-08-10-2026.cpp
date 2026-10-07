class Solution {
public:
    void help(int i,int n,int bal,string &s,string &temp,set<string>  &mp,int &maxDeletions){
        if(bal<0) return ;

        if(i==n){
            if(bal==0){
                int deletions=n-temp.size();
                if(deletions<maxDeletions){
                    mp.clear();
                    maxDeletions=deletions;
                    mp.insert(temp);
                    cout<<temp<<'\n';
                }else if(deletions==maxDeletions){
                    mp.insert(temp);
                    cout<<temp<<'\n';
                }
            }
            return;
        }
        
        if(s[i]>='a' && s[i]<='z'){
            temp.push_back(s[i]);
            help(i+1,n,bal,s,temp,mp,maxDeletions);
            temp.pop_back();
        }
        else{
            // pick
            bal+=s[i]=='(' ? 1 : -1;
            temp.push_back(s[i]);
            help(i+1,n,bal,s,temp,mp,maxDeletions);
            bal-=s[i]=='(' ? 1 : -1;
            temp.pop_back();

            // remove
            help(i+1,n,bal,s,temp,mp,maxDeletions);
        }
        
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp="";
        int n=s.size();
        set<string> mp;
        int maxDeletions=INT_MAX;
        help(0,n,0,s,temp,mp,maxDeletions);
        vector<string> ans;
        for(auto &it:mp){
            ans.push_back(it);
        }

        return ans;
    }
};