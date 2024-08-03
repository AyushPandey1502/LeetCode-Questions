class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        if (root == NULL)
            return root;
        else if (root->left == NULL)
            return root;
        else
            return findMin(root->left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left != NULL && root->right != NULL) {
                TreeNode* insuccessor = findMin(root->right);
                root->val = insuccessor->val;
                root->right = deleteNode(root->right, insuccessor->val);
            } else {
                TreeNode* dummy = root;
                if (dummy->right == NULL)
                    return dummy->left;
                if (dummy->left == NULL)
                    return dummy->right;
            }
        }
        return root;
    }
};