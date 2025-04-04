class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto [leftDepth, leftLCA] = dfs(root->left);
        auto [rightDepth, rightLCA] = dfs(root->right);

        if (leftDepth > rightDepth) return {leftDepth + 1, leftLCA};
        if (rightDepth > leftDepth) return {rightDepth + 1, rightLCA};
        return {leftDepth + 1, root};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
