class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                sum+=st.size()*st.size();
            }
        }
        return sum;
    }
};

// 1 2 1

// 1
// 1 2
// 1 2 1
// 2
// 2 1
// 1