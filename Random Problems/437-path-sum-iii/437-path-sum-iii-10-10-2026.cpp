/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root,int target,long long currSum,int &cnt){
        
        if(root==NULL) return;

        // Here what I am thinking is adding the parent into sum and then finding a path or dont include that is make currSum to zero
        
        // Adding parent's value get a path

        currSum+=root->val;
        if(currSum==target) cnt++;
        help(root->left,target,currSum,cnt);
        help(root->right,target,currSum,cnt);
    }

    // turns out logic was correct but should not be doen in the same path
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL) return 0;

        // for every node do a dfs down
        int cnt=0;

        help(root,targetSum,0,cnt);
        cnt+=pathSum(root->left,targetSum);
        cnt+=pathSum(root->right,targetSum);

        return cnt;
    }
};
