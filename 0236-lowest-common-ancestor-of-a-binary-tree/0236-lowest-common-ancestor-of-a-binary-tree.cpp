class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return nullptr;
        if(root == p) return p;
        if(root == q) return q;
        TreeNode* lst = dfs(root->left, p, q);
        TreeNode* rst = dfs(root->right, p, q);
        if(lst && rst) return root;
        if(lst) return lst;
        return rst;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        return dfs(root, p, q);
    }
};