class Solution {
public:
    bool checkSymmetricity(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return (p == q);
        return (p->val == q->val) && checkSymmetricity(p->left, q->right) &&
               checkSymmetricity(p->right, q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return checkSymmetricity(root->left, root->right);
    }
};