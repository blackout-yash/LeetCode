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
	int maxAncestorDiffUtif(TreeNode* root, int _min, int _max) {
		if (root == NULL) return 0;

		int val = root -> val;
		_max = max(_max, val);
		_min = min(_min, val);

		int left = maxAncestorDiffUtif(root -> left, _min, _max),
		    right = maxAncestorDiffUtif(root -> right, _min, _max);
        
		return max({left, _max - _min, right});
	}

	int maxAncestorDiff(TreeNode* root) {
		if (root == NULL) return 0;

		int ans = maxAncestorDiffUtif(root, 1e9, -1e9);

		return ans;
	}
};