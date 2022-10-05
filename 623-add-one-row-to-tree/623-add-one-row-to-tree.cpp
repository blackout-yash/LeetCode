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

	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        
		int level = 1;
		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				TreeNode *node = q.front();
				q.pop();

				if (level + 1 == depth) {
					TreeNode *newNode1 = new TreeNode(val);
					TreeNode *newNode2 = new TreeNode(val);

					newNode1 -> left = node -> left;
					newNode2 -> right = node -> right;

					node -> left = newNode1;
					node -> right = newNode2;
				} else {
					if (node -> left) q.push(node -> left);
					if (node -> right) q.push(node -> right);
				}
			} level++;
			if (level == depth) break;
		}
		return root;
	}
};