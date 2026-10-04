class Solution {
public:
    int minRotations(string s) {
        int minRot=0; // test
        int prev=0;
        for(int i=0;i<s.size();i++){
            
            int curr=s[i]-'0';
            // cout<<prev<<" "<<curr<<' ';
            int op1=abs(curr-prev);
            int op2=abs(10-op1);

            minRot+=min(op1,op2);
            // cout<<min(op1,op2)<<'\n';
            prev=curr;
        }
        return minRot;
    }
};