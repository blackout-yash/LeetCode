class Solution {
public:
    void inOrder(TreeNode* root,vector<int>& v, int &ans){
        if(root == NULL) return;

        inOrder(root -> left, v, ans);
        if(v.size() && root->val - v.back() < ans) ans = root->val - v.back();
        
        v.push_back(root -> val);
        inOrder(root -> right, v, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector <int> v;
        inOrder(root, v, ans);
        return ans;
    }
};