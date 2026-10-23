class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        // get the lsat occurence of a-z
        // get the first occurence of A-Z

        vector<int> freqMapLower(26,-1),freqMapUpper(26,-1);

        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                freqMapLower[word[i]-'a']=i;
            }else{
                if(freqMapUpper[word[i]-'A']==-1){
                    freqMapUpper[word[i]-'A']=i;
                }
            }
        }

        int cnt=0;
        for(int i=0;i<26;i++) cnt+= (freqMapLower[i]!=-1 && freqMapUpper[i]!=-1 && (freqMapLower[i]<freqMapUpper[i]));
        
        return cnt;
    }
};