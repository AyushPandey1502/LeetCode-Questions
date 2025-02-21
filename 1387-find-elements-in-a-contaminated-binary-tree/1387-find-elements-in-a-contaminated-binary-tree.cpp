class FindElements {
public:
    TreeNode* root;

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        recoverTree(root);
    }

    void recoverTree(TreeNode* node) {
        if (node) {
            if (node->left) {
                node->left->val = 2 * node->val + 1;
                recoverTree(node->left);
            }
            if (node->right) {
                node->right->val = 2 * node->val + 2;
                recoverTree(node->right);
            }
        }
    }

    bool findElement(TreeNode* node, int x) {
        if (node) {
            if (node->val == x) return true;
            return findElement(node->left, x) || findElement(node->right, x);
        }
        return false;
    }

    bool find(int target) {
        return findElement(root, target);
    }
};
