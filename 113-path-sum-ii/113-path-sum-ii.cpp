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
        return (root -> left == NULL && root -> right == NULL);
    }
    
    void pathSum(TreeNode* root, int targetSum, vector <int> &temp, vector<vector<int>> &ans) {
        if(root ==  NULL) return;
        
        int val = root -> val;
        temp.push_back(val);
        if(isLeaf(root)){
            if(val == targetSum) ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        pathSum(root -> left, targetSum - val, temp, ans);
        pathSum(root -> right, targetSum - val, temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int> temp;
        vector<vector<int>> ans;
        
        pathSum(root, targetSum, temp, ans);
        
        return ans;
    }
};