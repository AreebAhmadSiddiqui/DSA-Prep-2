class Solution {
public:
    int getFirstElementGraterThanTarget(vector<int> &nums,int target){
        int s=0;
        int e=nums.size()-1;

        int ans=nums.size();
        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                s=mid+1;
            }else{
                ans=mid;
                e=mid-1;
            }
        }

        return ans;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        // Brute TLE expected

        // vector<long long> ans;
        // for(int i=0;i<queries.size();i++){
        //     int target=queries[i];

        //     long long operations=0;

        //     for(int i=0;i<nums.size();i++){
        //         operations+=abs(nums[i]-target);
        //     }

        //     ans.push_back(operations);
        // }

        // return ans;


        // Very good question

        // So what happens in each operation

        // some values increase while some decrease

        // Given a target can you tell me which values will increase/decrease

        // Yes -> values less than target should increase while greater ones need to decrease

        // What does this suggest??

        // Sorting yes

        // Ok lets sort

        // 1  3  6  8

        // now what it is your target ??? lets take 5 for example

        // elements less than 5 are till index 1 ( how can you find this optimally??? Binary search yes )

        // So what needes to be done to these elements

        // 1+4
        // 3+2 to become 5

        // but will you solve it one by one??? this will make O(n2) so we can precompute it right??? Yes prefix sum


        // prefixSum = 1 4 10 18

        // 1+4
        // 3+2

        // evntually is prefixSum[1]+What??? ( since we want to make the left elements to be 5 then 5*2 would be the final sum)
        // we currently have 4

        // how much in deficit ( 6 which is that 4+2)

        // And similary on the right side


        // So algo is

        // 1. sort
        // 2. getPrefixSum

        // 3. for every query
        //     3.1 BS the first element greater than target / or last element smaller than target
        //     3.2 get the moves needed

        // 4. return ans;
        

        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<long long> prefixSum(n,0);
        for(int i=0;i<n;i++){
            if(i==0) prefixSum[i]=nums[i];
            else prefixSum[i]=nums[i]+prefixSum[i-1];
        }

        vector<long long> ans;

        for(int i=0;i<queries.size();i++){
            int target=queries[i];
            long long sum=0;
            int idx=getFirstElementGraterThanTarget(nums,target);
            // cout<<idx<<'\n';
            // get the left part (n-1)

            long long leftSum=idx!=0 ? prefixSum[idx-1] : 0;

            long long rightSum=0;
            if(idx==n) rightSum=0;
            else if(idx==0) rightSum=prefixSum[n-1];
            else rightSum=prefixSum[n-1]-prefixSum[idx-1];

            // cout<<leftSum<<' '<<rightSum<<'\n';

            long long leftSumRequired=target*1ll*(idx);

            long long rightSumRequired=target*1ll*(n-idx);
            // cout<<leftSumRequired<<" "<<rightSumRequired<<'\n';


            ans.push_back((leftSumRequired-leftSum)+(rightSum-rightSumRequired));
            
        }

        return ans;
    }
};