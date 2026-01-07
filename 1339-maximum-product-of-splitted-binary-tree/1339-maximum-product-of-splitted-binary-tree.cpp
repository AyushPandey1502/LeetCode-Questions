class Solution {
public:
    const int MOD = 1e9 + 7;
    long long result = INT_MIN, total = 0;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        result = max(result, (total - sum) * sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root);
        return result % MOD;
    }
};
