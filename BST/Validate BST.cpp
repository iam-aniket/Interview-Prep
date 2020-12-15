class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        vector<int> ans;
        inorder(root,ans);
        int f = 0;
        for(int i = 1; i < ans.size();i++)
        {
            if(ans[i] > ans[i-1])continue;
            else
            {
                f = 1;
                break;
            }
        }
        if(f)
            return 0;
        else
            return 1;
    }
    void inorder(TreeNode* root,vector<int>& ans)
    {
        if(root == NULL)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};
