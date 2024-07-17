class Solution {
public:
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int>& set,
                          vector<TreeNode*>& result) {
        if (root == NULL)
            return root;
        root->left = deleteNodes(root->left, set, result);
        root->right = deleteNodes(root->right, set, result);
        if (set.find(root->val) != set.end()) {
            if (root->left != NULL) {
                result.push_back(root->left);
            }
            if (root->right != NULL) {
                result.push_back(root->right);
            }
            return NULL;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        if (root == NULL)
            return result;
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        deleteNodes(root, set, result);
        if (set.find(root->val) == set.end()) {
            result.push_back(root);
        }
        return result;
    }
};