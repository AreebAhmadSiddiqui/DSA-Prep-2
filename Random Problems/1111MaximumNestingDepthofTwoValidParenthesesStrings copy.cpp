class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // vector<int> ans(seq.size(),1);
        
        // This would have worked If I could pick elements from anywhere and rearragnge them

        // Since it is a VPS so count of '(' and ')' would be equal so we have to form like this ()()()()()...n ( even ) terms
        // get the size / 2

        // size 

        // 4 -> ()()  A (1) -> B (1) ( Number denotes pairs)
        // 6 -> ()()() A (2) -> B (1)
        // 8 -> ()()()() A (2) -> B(2)
        // 10 -> ()()()()() A (3) -> B(2)
        // 12 -> ()()()()()() A (3) -> B (3)
        // 14 -> ()()()()()()() A (4) -> B (3)

        // So formula is [size/4] is size%4==0 else [size/4]+1

        // 1> = Left side >= Right Side ( A >= B && 1>=A-B>=0)

        // int cntOpening=0,cntClosing=0; // -> For A
        // int sz=seq.size();

        // if(sz%4==0) cntOpening=cntClosing=sz/4;
        // else cntOpening=cntClosing=sz/4+1;


        // for(int i=0;i<sz;i++){
        //     if(cntOpening && seq[i]=='(') {
        //         ans[i]=0;
        //         cntOpening--;
        //     }else if(cntClosing && seq[i]==')'){
        //         ans[i]=0;
        //         cntClosing--;
        //     }
        // }

        // return ans;


        // So its like one observation is that the max depth wont be > 1 so what you can do is keep dividing elements into groups based on the depth

        vector<int> ans;
        int depth = 0;
        for (char c : seq) {
            if (c == '(') {
                depth++;
                ans.push_back(depth % 2);
            } else {
                ans.push_back(depth % 2);
                depth--;
            }
        }
        return ans;
    }
};