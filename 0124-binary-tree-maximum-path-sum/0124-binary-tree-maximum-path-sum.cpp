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
    int maxPathSumUtil(TreeNode* root, int &ans) {
        if(root == NULL) return 0;
        
        int val = root -> val,
            left = maxPathSumUtil(root -> left, ans),
            right = maxPathSumUtil(root -> right, ans);
        
        left = max(0, left);
        right = max(0, right);
        ans = max(ans, left + val + right);
        
        return val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int ans = -1e9;
        maxPathSumUtil(root, ans);
        
        return ans;
    }
};