class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // In these type of questions where incremeent and decrement is allowed
        // try to make every element to what??

        // min -> more moves needed
 
        // middle -> this is optimal

        // max -> more moves needed

        //         1 , 10 , 2 , 9   ( if we sort 1 2 9 10 median is 2 or 9 )

        // 2       1   8    0   7   -> 16

        // 9       8   1    7   0   -> 16


        sort(nums.begin(),nums.end());

        int n=nums.size();
        
        int median=nums[n/2];

        int movesNeeded=0;

        for(int i=0;i<n;i++){
            movesNeeded+=abs(median-nums[i]);
        }

        return movesNeeded;

    }
};