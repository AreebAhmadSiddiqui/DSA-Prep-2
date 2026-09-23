class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
            // Can I find something else
            // Instead of finding the sum of end points can I target to find something in the middle??
            // Yes we can get totalSum-sumOfEndpoints
            // basically I want to create sumOfEndpoints = x
            // So totalSum-x lets say its is k
            
            // I want to find the maximum length subarray whose sum is equal to k
            // n- length of subarray will give me the minimum operations needed

            // int sum=0;
            // int maxLen=0;
            // for(auto &it:nums) sum+=it;

            // int k=sum-x;
            // unordered_map<int,int> mp; // {sum,oldestIdx}
            // sum=0;
            // mp[0]=-1;
            // for(int i=0;i<nums.size();i++){
            //     sum+=nums[i];
            //     int rem=sum-k;
             
            //     if(mp.find(rem)!=mp.end()){
            //         int idx=mp[rem];
            //         maxLen=max(maxLen,i-idx);
            //     }

            //     if(mp.find(sum)==mp.end()) mp[sum]=i; // store first index to maximize
            // }

            // if(k==0) return nums.size();
            // return maxLen==0 ? -1 : nums.size()-maxLen;


            // Since everything is positive I can use sliding window as well
            int sum=0;
            int maxLen=0;
            for(auto &it:nums) sum+=it;

            int k=sum-x;
            if(k==0) return nums.size();
            if(k<0) return -1;
            int i=0;
            sum=0;
            for(int j=0;j<nums.size();j++){
                
                sum+=nums[j];

                while(sum>k){
                    sum-=nums[i++];
                }

                if(sum==k) maxLen=max(maxLen,j-i+1);
            }

            return maxLen==0 ? -1 : nums.size()-maxLen;
    }
};