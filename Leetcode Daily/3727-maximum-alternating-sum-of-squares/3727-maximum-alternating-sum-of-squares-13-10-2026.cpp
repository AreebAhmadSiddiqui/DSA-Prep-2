class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // Initial thinking
        // sum of sqaure of even indices - sum of squares of odd indices
        // since they are sqaure so no need to take care of - elements
        // maximize the even positions and minimize the odd positions
        // so keep all big players in even positions and small players in odd

        vector<long long> temp;

        for(auto &it:nums){
            temp.push_back((it*1ll*it));
        }

        sort(temp.begin(),temp.end());

        // get the players of the odd indices n/2 for n=5 2 in odd and 3 in even
        // for n=4 2 in odd and 2 in even

        int boundary=nums.size()/2; // these many elements are the smallest and put them in the odd position

        long long sum=0;

        for(int i=0;i<boundary;i++){
            sum-=temp[i];
        }

        for(int i=boundary;i<nums.size();i++){
            sum+=temp[i];
        }

        return sum;
    }
};