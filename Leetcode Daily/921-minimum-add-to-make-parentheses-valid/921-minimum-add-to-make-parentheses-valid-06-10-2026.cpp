class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0;
        int additions=0;
        for(int i=0;i<s.size();i++){
            bal+=s[i]=='(' ? +1 : -1;

            if(bal<0){ // got unbalanced need to add a opening bracket
                additions++;
                bal=0;
            }
        }
        return additions+bal;
    }
};