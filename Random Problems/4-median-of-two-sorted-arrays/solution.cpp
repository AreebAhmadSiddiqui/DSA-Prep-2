class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Brute is store in an arrau and find the median
        
        // Better is ( cnt kar lo jab mid post ae to use store kar lo)
        
        // Optimal
        
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        
        int start=0;
        int end=n;
        
        double ans=0.0;
        while(start<=end){
            int cut1 = start+(end-start)/2;
            int cut2 = (m+n+1)/2-cut1;
            
            int l1= cut1==0 ? -1e9 : nums1[cut1-1];
            int l2= cut2==0 ? -1e9 : nums2[cut2-1];
            int r1= cut1==n ? 1e9 : nums1[cut1];
            int r2= cut2==m ? 1e9 : nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((m+n)&1) return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }else if(l1>r2){
                end=cut1-1;
            }else{
                start=cut1+1;
            }
        }
        return 0.0;
    }
};