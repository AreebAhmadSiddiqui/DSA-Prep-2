// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void help(TreeNode* root,int target,long long currSum,int &cnt){
        
//         if(root==NULL) return;

//         // Here what I am thinking is adding the parent into sum and then finding a path or dont include that is make currSum to zero
        
//         // Adding parent's value get a path

//         currSum+=root->val;
//         if(currSum==target) cnt++;
//         help(root->left,target,currSum,cnt);
//         help(root->right,target,currSum,cnt);
//     }

//     // turns out logic was correct but should not be doen in the same path
//     int pathSum(TreeNode* root, int targetSum) {
        
//         if(root==NULL) return 0;

//         // for every node do a dfs down
//         int cnt=0;

//         help(root,targetSum,0,cnt);
//         cnt+=pathSum(root->left,targetSum);
//         cnt+=pathSum(root->right,targetSum);

//         return cnt;
//     }
// };


// Another Hashmap Solution

// So intuition is every path is like an array of numbers right?? can I find cnt of paths(subarrays) suming to target
// Yes we can use hashmap and prefix logic

class Solution {
public:
    void help(TreeNode *root,int target,long long currSum,unordered_map<long long,long long> &mp,int &cnt){
        if(root==NULL) return;

        currSum+=root->val;

        long long prefix=currSum-target;
        // if(currSum==target) cnt++;
        if(mp.find(prefix)!=mp.end()) cnt+=mp[prefix];

        mp[currSum]++;

        help(root->left,target,currSum,mp,cnt);
        help(root->right,target,currSum,mp,cnt);

        // Backtrack because this path we are not gonna chose next
        mp[currSum]--;  

    //     1
    //    2  3  lets se we went on the left path map will store 1->1,3->1 when we change path or array then that currSumm should be removed na hence removing it

    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,long long> mp; //{sum,cnt};

        mp[0]=1; // initial set;

        int cnt=0;
        help(root,targetSum,0,mp,cnt);

        return cnt;
    }
};
