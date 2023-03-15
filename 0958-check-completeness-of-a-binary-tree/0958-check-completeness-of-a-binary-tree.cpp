class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        
        bool isNull = false; 
        while(!q.empty()){ 
            int levelSize = q.size();
            while(levelSize--){    
                TreeNode* curr = q.front();
                q.pop();
                if(!curr) isNull = true; 
                else{
                    if(isNull) return false; 
                    q.push(curr -> left);
                    q.push(curr -> right);
                }
            }
        }
        return true;
    }
};