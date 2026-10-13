class Solution {
public:
    long long help(int i,int lastEleParity,int n,vector<int> &nums,vector<vector<long long>> &dp){
        if(i==n) return 0;

        if(dp[i][lastEleParity]!=-1) return dp[i][lastEleParity];

        long long notPick=0+help(i+1,lastEleParity,n,nums,dp);
        long long pick=0;

        bool isCurrEven = lastEleParity==1;

        if(isCurrEven) pick=nums[i]+help(i+1,!isCurrEven,n,nums,dp);
        else pick=-nums[i]+help(i+1,!isCurrEven,n,nums,dp);

        return dp[i][lastEleParity]=max(pick,notPick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long> (2, -1));
        return help(0,1,n,nums,dp);
    }
};