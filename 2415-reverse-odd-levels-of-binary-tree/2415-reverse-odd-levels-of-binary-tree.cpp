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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        
        vector <TreeNode*> odd, even;
        int cnt = 1;
        even.push_back(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                
                if(curr -> left != NULL) {
                    q.push(curr -> left);
                    if(cnt & 1) odd.push_back(curr -> left);
                    else even.push_back(curr -> left);
                } 
                
                if(curr -> right != NULL){
                    q.push(curr -> right);
                    if(cnt & 1) odd.push_back(curr -> right);
                    else even.push_back(curr -> right);
                }
            }
            
            if(cnt & 1) {
                reverse(odd.begin(), odd.end());
                int i = 0;
                for(auto x: even) {
                    if(i == odd.size()) break;
                    x -> left = odd[i];
                    x -> right = odd[i + 1];
                    i += 2;
                } 
                even.clear();
            } else {
                int i = 0;
                for(auto x: odd) {
                    if(i == even.size()) break;
                    x -> left = even[i];
                    x -> right = even[i + 1];
                    i += 2;
                } 
                odd.clear();
            } cnt++;
        }
        return root;
    }
};