class Solution {
public:
    
    // Brute O(n3)
//     vector<vector<int>> threeSum(vector<int>& nums) {

//         set<vector<int>> st;

//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     int sum=nums[i]+nums[j]+nums[k];
//                     if(sum==0){
//                         vector<int> temp={nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>> (st.begin(),st.end());
//     }
    
    // Optimal
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                
                int sum=nums[i];
                sum+=nums[l];
                sum+=nums[r];
                
                if(sum==0){
                    vector<int> temp={nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    while(l<r && nums[l]==temp[1]) l++;
                    while(l<r && nums[r]==temp[2]) r--;
                }else if(sum<0){
                    l++;
                }else{
                    r--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};