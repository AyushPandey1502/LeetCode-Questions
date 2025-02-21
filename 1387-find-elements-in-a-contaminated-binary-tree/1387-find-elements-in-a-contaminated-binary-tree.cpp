class FindElements {
private:
    unordered_set<int> values;

    void recoverTree(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        values.insert(val);
        recoverTree(node->left, 2 * val + 1);
        recoverTree(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) recoverTree(root, 0);
    }

    bool find(int target) {
        return values.count(target);
    }
};
