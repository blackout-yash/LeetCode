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
    vector<TreeNode*> generateTrees(vector <int> &node) {
        if(node.empty()) return {NULL};
        
        vector <TreeNode*> ans;
        for(auto x: node) {
            vector <int> temp1, temp2;
            for(auto y: node) {
                if(x == y) {}
                else if(x > y) temp1.push_back(y);
                else temp2.push_back(y);
            }
            vector <TreeNode*> left = generateTrees(temp1);
            vector<TreeNode*> right = generateTrees(temp2);
            for(auto it1: left) {
                for(auto it2: right) {
                    TreeNode* curr = new TreeNode(x);
                    curr -> left = it1;
                    curr -> right = it2;
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    
    vector <TreeNode*> generateTrees(int n) {
        vector <int> node;
        for(int i = 1; i <= n; i++) node.push_back(i);
        
        vector <TreeNode*> ans = generateTrees(node);
        
        return ans;
    }
};