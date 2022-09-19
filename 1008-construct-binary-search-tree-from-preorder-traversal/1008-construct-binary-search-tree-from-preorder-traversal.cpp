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
    void bstFromPreorder(TreeNode* root, int i, int j, vector <int> &preorder) {
        if(i > j) return;
        else if(i == j) {
            root -> val = preorder[i];
            return;
        }
        
        int index = j + 1;
        for(int k = i + 1; k <= j; k++){
            if(preorder[k] > preorder[i]) {
                index = k;
                break;
            }
        }
        
        root -> val = preorder[i];
        if(i + 1 <= index - 1) {
            root -> left = new TreeNode();
            bstFromPreorder(root -> left, i + 1, index - 1, preorder);
        }
        
        if(index <= j) {
            root -> right = new TreeNode();
            bstFromPreorder(root -> right, index, j, preorder);
        }
    }
    
    TreeNode* bstFromPreorder(vector <int> &preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode();
        bstFromPreorder(root, 0, n - 1, preorder);
        
        return root;
    }
};