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
    int total(TreeNode* root) {
        if(root == NULL) return 0;
        int left = total(root -> left),
            right = total(root -> right);
        return 1 + left + right;
    }
    
    int height(TreeNode* root, vector <pair <int, int>> &child) {
        if(root == NULL) return 0;
        int left = height(root -> left, child),
            right = height(root -> right, child);
        child[root -> val] = {left, right};
        return 1 + max(left, right);
    }
    
    void impact(TreeNode* root, int flag, vector <pair <int, int>> &child, vector <int> &pre) {
        if(root == NULL) return;
        
        int curr = root -> val,
            left = child[curr].first,
            right = child[curr].second;
        pre[curr] = flag;
        
        impact(root -> left, min(flag, max(0, left - right)), child, pre);
        impact(root -> right, min(flag, max(0, right - left)), child, pre);
    }
    
    vector <int> treeQueries(TreeNode* root, vector <int> &queries) {
        int totalNode = total(root);
        vector <int> pre(totalNode + 1, 1);
        vector <pair <int, int>> child(totalNode + 1);
        int ht = height(root, child) - 1;
        impact(root, 1e9, child, pre);
        
        vector <int> ans;
        for(auto x: queries) ans.push_back(ht - pre[x]);
        return ans;
    }
};