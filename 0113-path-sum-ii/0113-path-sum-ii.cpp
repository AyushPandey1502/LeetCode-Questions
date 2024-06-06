class Solution {
public:
    vector<vector<int>> result;

    void getPaths(TreeNode* root, vector<int>& path, int targetSum) {
        if (root == NULL)
            return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL && targetSum == 0) {
            result.push_back(path);
        } else {
            getPaths(root->left, path, targetSum);
            getPaths(root->right, path, targetSum);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        getPaths(root, path, targetSum);
        return result;
    }
};
