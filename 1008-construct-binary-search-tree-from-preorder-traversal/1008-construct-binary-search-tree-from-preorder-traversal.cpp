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
    TreeNode* bstFromPreorder(int &i, int max, vector<int> &preorder) {
        if(i == preorder.size() || preorder[i] > max) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = bstFromPreorder(i, root -> val, preorder);
        root -> right = bstFromPreorder(i, max, preorder);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        int i = 0;
        return bstFromPreorder(i, 1e9, preorder);
    }
};