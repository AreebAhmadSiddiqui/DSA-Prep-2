class Solution {
public:
    int getSum(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    int minSwaps(vector<int>& nums) {
        // this was a new concept to me
        // so we sort the elements and and then do a cycle decomposition
        // like lets say arr elements are [3,2,1] sorted would be [1,2,3]

        // for every element we check their final position

        // a[0] -> a[2]
        // a[2] -> a[0] ( one cycle)
        // a[1] -> a[1]  

        // a[0] -> a[2] -> a[0] ( cycle ) then how many swaps needed ??? cycle length - 1

        // My initial thought was to count the mismatches and divide / 2

        // Ex - [2,3,4,1]

        //      [1,2,3,4]

        // according to my logic it mismatch = 4, so swap would be 4/2 = 2 ( is this correct??? ) 
        // NOOOO!!  Min 3 swaps are needed

        // Cycle method

        // a[0] -> a[1]
        // a[1] -> a[2]
        // a[2] -> a[3]
        // a[3] -> a[0]

        // this is a cycle  a[0] -> a[1] -> a[2] -> a[3] -> a[0]  ( cycle length is 4 hence 3 swaps are needed )


        // But why -1 swaps though its easy but see here

        // the reason for cycle length − 1 is that each swap can reduce the number of misplaced elements in a cycle by at most one net step toward resolving that cycle.
        // Let's take a cycle of length 4:
        // \[
        // 0\rightarrow1\rightarrow2\rightarrow3\rightarrow0
        // \]

        // Suppose the array is [2, 3, 4, 1].
        // Initially: 4 elements are misplaced.
        // - Swap 1 and 4 → [1, 3, 4, 2] — one element is now correct.
        // - Swap 2 and 3 → [1, 2, 4, 3] — another element is correct.
        // - Swap 3 and 4 → [1, 2, 3, 4] — the last two are correct.
        // Total: 3 swaps.
        // The mathematical reason
        // A cycle of length \(L\) requires at least \(L-1\) swaps because one swap can split at most one cycle into two cycles, increasing the total number of cycles by at most one.
        // Initially, one cycle exists. To turn it into \(L\) separate cycles (every element correctly placed), you need at least \(L-1\) swaps.
        // \[
        // \boxed{\text{Swaps}=L-1}
        // \]

        // For example, a cycle of length 4 needs 3 swaps; a cycle of length 2 needs 1 swap. A cycle of length 1 is already correct and needs \(1-1=0\) swaps.


        // sort according to the question

        int n=nums.size();
        vector<pair<int,int>> temp(n);
        
        for(int i=0;i<n;i++){
            int num=nums[i];
            int digSum=getSum(nums[i]);

            temp[i]={digSum,num}; // for tiebreaker
        }

        sort(temp.begin(),temp.end(),comp);
        
        unordered_map<int,int> finalPos;

        for(int i=0;i<n;i++){
            int num=temp[i].second;
            finalPos[num]=i;
        }

        // for(auto &it:finalPos) cout<<it.first<<" "<<it.second<<'\n';

        vector<int> vis(n,0);
        
        int swapsNeeded=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){

                int num=nums[i];
                vis[i]=1;

                int targetIdx=finalPos[num];

                // cout<<i<<" "<<targetIdx<<'\n';
                int cycleNodes=1;
                while(!vis[targetIdx]){
                    // cout<<nums[i]<<" "<<nums[targetIdx]<<'\n';
                    cycleNodes++;
                    vis[targetIdx]=1;
                    targetIdx=finalPos[nums[targetIdx]];
                }

                // cout<<cycleNodes<<'\n';
                if(cycleNodes>1) swapsNeeded+=cycleNodes-1;
            }
        }
        
        // [18,43,34,16] -> 

        // [16,34,43,18]
        return swapsNeeded;
    }
};