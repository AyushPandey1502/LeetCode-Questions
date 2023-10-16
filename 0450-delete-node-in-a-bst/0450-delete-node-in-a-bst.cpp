class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        if (root == NULL) return NULL;
        else if (root->left == NULL) return root;
        else return findMin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left != NULL && root->right != NULL) {
                TreeNode* insucc = findMin(root->right);
                root->val = insucc->val;
                root->right = deleteNode(root->right, insucc->val);
            } else {
                TreeNode* temp = root;
                TreeNode* child = NULL;

                if (!temp->right) {
                    child = temp->left;
                }
                if (!temp->left) {
                    child = temp->right;
                }
                delete temp;
                return child;
            }
        }
        return root;
    }
};
