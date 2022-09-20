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

class BITIterator {
public:
	bool reverse;
	stack <TreeNode*> s;

	BITIterator(TreeNode* root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}

	int next() {
		TreeNode* curr = s.top();
		s.pop();

		if (reverse) pushAll(curr -> left);
		else pushAll(curr -> right);

		return curr -> val;
	}

	void pushAll(TreeNode* root) {
		while (root != NULL) {
			s.push(root);
			if (reverse) root = root -> right;
			else root = root -> left;
		}
	}
};

class Solution {
public:
	bool findTarget(TreeNode* root, int k) {
		if (root == NULL) return false;

		BITIterator l = BITIterator(root, false);
		BITIterator r = BITIterator(root, true);

		int i = l.next(), j = r.next();
		while (i < j) {
			if (i + j == k) return true;
			else if (i + j > k) j = r.next();
			else i = l.next();
		}
		return false;
	}
};