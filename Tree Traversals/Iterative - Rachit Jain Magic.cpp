//IN-ORDER Rachit Jain Trick - stack + unordered map counting
//Refer https://www.youtube.com/watch?v=5BzvEmscu-o
//https://github.com/rachitiitr/DataStructures-Algorithms/blob/master/Tricks/iterative-tree-traversal-1.cpp
class Solution {
public:

	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		inorder(root, ans);
		return ans;
	}
	unordered_map<TreeNode*, int> cnt;
	void inorder(TreeNode* root, vector<int>& ans)
	{
		stack <TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			TreeNode* cur = s.top();
			if (cur == NULL)
			{
				s.pop();
				continue;
			}

			if (cnt[cur] == 0)s.push(cur->left);
			else if (cnt[cur] == 1)ans.push_back(cur->val);
			else if (cnt[cur] == 2)s.push(cur->right);
			else
				s.pop();

			cnt[cur]++;
		}
	}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//POST-ORDER
if (cnt[cur] == 0)s.push(cur->left);
else if (cnt[cur] == 1)s.push(cur->right);
else if (cnt[cur] == 2)ans.push_back(cur->val);
else
	s.pop();

//PRE-ORDER
/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
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

	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		preorder(root, ans);
		return ans;
	}
	unordered_map<TreeNode*, int> cnt;
	void preorder(TreeNode* root, vector<int>& ans)
	{
		stack <TreeNode*> s;
		s.push(root);

		while (!s.empty())
		{
			TreeNode* cur = s.top();
			if (cur == NULL)
			{
				s.pop();
				continue;
			}

			if (cnt[cur] == 0)ans.push_back(cur->val);
			else if (cnt[cur] == 1)s.push(cur->left);
			else if (cnt[cur] == 2)s.push(cur->right);
			else
				s.pop();

			cnt[cur]++;
		}
	}
};
