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
    bool isLeaf(TreeNode* root){
        return root -> left == NULL && root -> right == NULL;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        else if(isLeaf(root)) {
            if(targetSum == root -> val) return true;
            return false;
        }
        
        bool ans1 = hasPathSum(root -> left, targetSum - root -> val);
        bool ans2 = hasPathSum(root -> right, targetSum - root -> val);
        
        return(ans1 | ans2);
    }
};