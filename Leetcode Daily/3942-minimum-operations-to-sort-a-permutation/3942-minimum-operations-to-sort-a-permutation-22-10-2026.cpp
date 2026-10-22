class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        // notice that this permutation rotation is only possible if the array was originally sorted and rotated
        
        // These operations are left rotate
        // rev ( left rotate ) rev this right rotation
        // so basically we want to see if left rotating gives minimal result or the right one


        // Now we need to see if the array is ascending sorted / rotated or descending

        int ascMismatch=0,descMismatch=0;
        int zeroIdx=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            // for a valid rotated sorted array only one pair will be misplaced
            if(nums[i]>=nums[(i+1)%n]) ascMismatch++;

            if(nums[i]<=nums[(i+1)%n]) descMismatch++;

            if(nums[i]==0) zeroIdx=i;
        }

        // For ascending we have two options of sorting it

        // Case 1

        // leftRotate ( if the zeroPos is x => then x rotations are needed )

        // Case 2

        // right rotate ( but with the operations i can reverse left rotate and again reverse )
        // reversing the ascending orderd will make the array desceding rotated
        // here if zeroPos is x then right rotate will be (n-zeroPos)

        int ans=-1;

        cout<<ascMismatch<<" "<<descMismatch<<'\n';

        if(ascMismatch==1){
            ans=min(zeroIdx,1+(n-zeroIdx)+1); // 1 for each reverse
        }


        // For descending sorted

        // Case 1 -> ex 1 0 4 3 2 -> left rotate + reverse ( zerPos+1 + 1)
        // Case 2 -> reverse + right rotate ( 1 + ( n-zeroPos-1))

        else if(descMismatch==1){
            ans=min(zeroIdx+1+1,1+(n-zeroIdx-1));
        }

        return ans;
    }
};