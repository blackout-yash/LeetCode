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
    bool isLeaf(TreeNode* root) {
        return (root -> left == NULL) && (root -> right == NULL);
    }
    
    void leaf(TreeNode* root, vector <int> &temp) {
        if(root == NULL) return;
        else if(isLeaf(root)) temp.push_back(root -> val);
        
        leaf(root -> left, temp);
        leaf(root -> right, temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> temp1, temp2;
        leaf(root1, temp1);
        leaf(root2, temp2);
        
        return (temp1 == temp2);
    }
};