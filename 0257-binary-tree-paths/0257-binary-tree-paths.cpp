class Solution {
public:
    vector<string> result;

    void getPaths(TreeNode* root, string path) {
        if (root == NULL) return;
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path); 
        } else {
            path += "->";
            getPaths(root->left, path);
            getPaths(root->right, path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root != NULL) {
            getPaths(root, "");
        }
        return result;
    }
};
