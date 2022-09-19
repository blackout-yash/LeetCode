/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        int val = root -> val;
        
        TreeNode* left = NULL;
        if(val > p -> val || val > q -> val) left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = NULL;
        if(val < p -> val || val < q -> val) right = lowestCommonAncestor(root -> right, p, q);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
};