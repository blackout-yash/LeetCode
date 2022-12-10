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
#define ll long long
class Solution {
public:
	ll mod = 1e9 + 7;

	ll sum(TreeNode* root) {
		if (root == NULL) return 0;

		ll val = root -> val,
		    left = sum(root -> left),
		    right = sum(root -> right);

		return (left + val + right);
	}

	ll maxProductUtil(TreeNode* root, ll sum, ll &ans) {
		if (root == NULL) return 0;

		ll val = root -> val,
		    left = maxProductUtil(root -> left, sum, ans),
		    right = maxProductUtil(root -> right, sum, ans);

		ll leftPro = (left * (sum - left)),
		    rightPro = (right * (sum - right));

		ans = max({ans, leftPro, rightPro});

		return (left + val + right);
	}

	int maxProduct(TreeNode* root) {
		ll total = sum(root), ans = 0;

		maxProductUtil(root, total, ans);

		return (ans % mod);
	}
};