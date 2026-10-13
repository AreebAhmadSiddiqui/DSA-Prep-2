class Solution {
public:
    // Memoiztion
    // long long help(int i,int lastEleParity,int n,vector<int> &nums,vector<vector<long long>> &dp){
    //     if(i==n) return 0;

    //     if(dp[i][lastEleParity]!=-1) return dp[i][lastEleParity];

    //     long long notPick=0+help(i+1,lastEleParity,n,nums,dp);
    //     long long pick=0;

    //     bool isCurrEven = lastEleParity==1;

    //     if(isCurrEven) pick=nums[i]+help(i+1,!isCurrEven,n,nums,dp);
    //     else pick=-nums[i]+help(i+1,!isCurrEven,n,nums,dp);

    //     return dp[i][lastEleParity]=max(pick,notPick);
    // }


    // Tabulation

    long long tabulation(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long> (2, 0));

        // for(int i=n-1;i>=0;i--){
        //     for(int lastEleParity=0;lastEleParity<=1;lastEleParity++){
                
        //         long long notPick=0+dp[i+1][lastEleParity];
                
        //         long long pick=0;

        //         bool isCurrEven = lastEleParity==1;

        //         if(isCurrEven) pick=nums[i]+dp[i+1][!isCurrEven];
        //         else pick=-nums[i]+dp[i+1][!isCurrEven];

        //         dp[i][lastEleParity]=max(pick,notPick);
        //     }
        // }


        // for(int i=n-1;i>=0;i--){
        //     // LastEleParity=0;
        //     long long notPick=0+dp[i+1][lastEleParity];
            
        //     long long pick=0;

        //     bool isCurrEven = lastEleParity==1;

        //     if(isCurrEven) pick=nums[i]+dp[i+1][!isCurrEven];
        //     else pick=-nums[i]+dp[i+1][!isCurrEven];

        //     // LastEleParity=1;
        //     dp[i][lastEleParity]=max(pick,notPick);

        //     long long notPick=0+dp[i+1][lastEleParity];
            
        //     long long pick=0;

        //     bool isCurrEven = lastEleParity==1;

        //     if(isCurrEven) pick=nums[i]+dp[i+1][!isCurrEven];
        //     else pick=-nums[i]+dp[i+1][!isCurrEven];

        //     dp[i][lastEleParity]=max(pick,notPick);
        // }

        // for(int i=n-1;i>=0;i--){
        //     // LastEleParity=0;
        //     long long notPick=0+dp[i+1][0];
            
        //     long long pick=-nums[i]+dp[i+1][1];
            
        //     dp[i][0]=max(pick,notPick);

        //     // LastEleParity=1;

        //     notPick=0+dp[i+1][1];
            
        //     pick=nums[i]+dp[i+1][0];

        //     dp[i][1]=max(pick,notPick);
        // }


        for(int i=n-1;i>=0;i--){
            dp[i][0]=max(-nums[i]+dp[i+1][1],dp[i+1][0]);
            dp[i][1]=max(nums[i]+dp[i+1][0],dp[i+1][1]);
        }

        return dp[0][1];
    }
    long long maxAlternatingSum(vector<int>& nums) {
        
        return tabulation(nums);
    }
};