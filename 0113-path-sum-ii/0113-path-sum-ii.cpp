class Solution {
public:
    vector<vector<int>> result;
    void getPaths(TreeNode* root, vector<int> arr, int targetSum) {
        if (root == NULL)
            return;
        arr.push_back(root->val);
        targetSum -= root->val;
        if (root->left == NULL && root->right == NULL && targetSum == 0) {
            result.push_back(arr);
            return;
        }
        getPaths(root->left, arr, targetSum);
        getPaths(root->right, arr, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return result;
        vector<int> arr;
        getPaths(root, arr, targetSum);
        return result;
    }
};