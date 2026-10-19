class Solution {
public:
    int lowerBnd(vector<int> &nums,int target){
        int ans=-1;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<target){
                start=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
    int upperBnd(vector<int> &nums,int target){
        int ans=-1;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]<target){
                start=mid+1;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerBnd(nums,target),upperBnd(nums,target)};
    }
};