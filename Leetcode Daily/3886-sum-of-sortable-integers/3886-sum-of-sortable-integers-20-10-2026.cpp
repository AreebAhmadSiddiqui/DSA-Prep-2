class Solution {
public:
    bool checkForOnePairMismatch(vector<int> &nums,int windowSize){
        
        // for the final array to be sorted I want to track min and max as well
        // max of previous block should be less than min of current block
        
        int n=nums.size();
        
        int prevMax=INT_MIN;
        for(int i=0;i<n;i+=windowSize){
            
            int cntMismatch=0;
            int minInBlock=nums[i];
            int maxInBlock=nums[i];

            // process each block
            for(int j=i;j<i+windowSize;j++){
                if(j+1<n && nums[j]>nums[j+1]){
                    cntMismatch++;
                }

                minInBlock=min(minInBlock,nums[j]);
                maxInBlock=max(maxInBlock,nums[j]);
            }

            // [12,18,14] // last element should be less than equal to first
            if(nums[i]<nums[i+windowSize-1]) cntMismatch++;

            // last element should be 
            if(cntMismatch>1 || prevMax>minInBlock) return false;

            prevMax=maxInBlock;
        }

        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        
        // for sure we want to get all k possible that we can get in sqrt(n)
        // then i have to run a k size window each to find the sorted array
        // observe if a sorted array is rotated either left/right there will be one consecutive pair
        // which will not hold for increasing order assume

        // 1 2 3 4 5

        // left  => [2,3,4,5,1],[3,4,5,1,2],[4,5,1,2,3],[5,1,2,3,4] // notice only one consecutive pair doesn't follow
        // right => [5,1,2,3,4],[4,5,1,2,3],[3,4,5,1,2],[2,3,4,5,1] // notice only one consecutive pair doesn't follow

        // 5 , 1 in this case
        
        // So for any subarray the elements should be same and <= 1 mismatch should be there
        // How do we get this efficiently????
        

        int n=nums.size();
        int sum=0;
        for (int k = 1; k <= sqrt(n); k++) {
            if (n % k == 0) {
                
                sum+=checkForOnePairMismatch(nums,k) ? k : 0;

                if (k != n / k) {
                    sum+=checkForOnePairMismatch(nums,n/k) ? n/k : 0;    
                }
            }
        }

        return sum;
    }
};