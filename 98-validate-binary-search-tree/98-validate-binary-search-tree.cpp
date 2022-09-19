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
    bool isValidBST(long _min, long _max, TreeNode* root) {
        if(root == NULL) return true;
        
        long val = root -> val;
        
        if(_min < val && val < _max) {}
        else return false;
        
        if(!isValidBST(_min, val, root -> left)) return false;
        if(!isValidBST(val, _max, root -> right)) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(-1e10, 1e10, root);
    }
};