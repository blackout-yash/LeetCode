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

class BSTIterator {
public:
	stack<TreeNode *> s;

	BSTIterator(TreeNode *root) {
		pushAll(root);
	}

	bool hasNext() {
		return !s.empty();
	}

	int next() {
		TreeNode* curr = s.top();
		s.pop();

		pushAll(curr -> right);

		return curr -> val;
	}

	void pushAll(TreeNode *root) {
		while (root != NULL) {
			s.push(root);
			root = root -> left;
		}
	}
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */