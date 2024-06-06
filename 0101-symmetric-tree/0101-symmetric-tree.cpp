class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return checkSymmetric(root-> left, root->right);
    }

    bool checkSymmetric(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL) return p == q;
        return p->val == q->val && checkSymmetric(p->left, q->right) && checkSymmetric(p->right, q->left);
    }
};