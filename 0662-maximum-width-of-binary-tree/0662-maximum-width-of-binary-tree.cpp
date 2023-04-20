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
	int widthOfBinaryTree(TreeNode* root) {
		ll ans = 0;
		if (root == NULL) return ans;

		queue <pair <TreeNode*, ll>> q;
		q.push({root, 0});

		ll prev = 0;
		while (!q.empty()) {
			ll size = q.size(), _min = 1e18, _max = -1e18;
			for (int i = 0; i < size; i++) {
				auto curr = q.front();
				q.pop();

				TreeNode* node = curr.first;
				ll index = curr.second - prev;

				if (node -> left != NULL) q.push({node -> left, index * 2 + 0});
				if (node -> right != NULL) q.push({node -> right, index * 2 + 1});

				_min = min(_min, index);
				_max = max(_max, index);
			} 
			prev = _min;
			ans = max(ans, _max - _min + 1);
		}
		return ans;
	}
};