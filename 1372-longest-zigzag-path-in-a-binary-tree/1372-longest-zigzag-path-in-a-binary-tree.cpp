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
    int longestZigZag(TreeNode* root, int left, int right) {
        if(!root) return max(left, right) - 1;
        
        int ans1 = longestZigZag(root -> left, right + 1, 0);
        int ans2 = longestZigZag(root -> right, 0, left + 1);        
        
        return max(ans1, ans2);
    }
    
    int longestZigZag(TreeNode* root) {
        return longestZigZag(root, 0, 0);
    }
};