1807. Evaluate the Bracket Pairs of a String

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto &it:knowledge){
            mp[it[0]]=it[1];
        }

        bool bracketOpen=false;
        string key="";
        string ans="";
        for(auto &ch:s){
            if(ch=='('){
                ans+=key;
                key="";
            }else if(ch>='a' && ch<='z'){
                key+=ch;
            }else{ // closing bracket
                if(mp.find(key)!=mp.end()) ans+=mp[key];
                else ans+='?';
                key="";
            }
        }
        return ans+key;
    }
};