// OPTIMIZED APPROACH
class Solution {
public:
    int sum = 0;
    void formGst(TreeNode* root) {
        if (root == NULL) return;
        formGst(root->right);
        root->val += sum;
        sum = root->val;
        formGst(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        formGst(root);
        return root;
    }
};
