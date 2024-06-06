class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = checkTrees(p, q);
        return result;
    }

    bool checkTrees(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        if (p->val != q->val)
            return false;
        bool leftCheck = checkTrees(p->left, q->left);
        bool rightCheck = checkTrees(p->right, q->right);
        return leftCheck && rightCheck;
    }
};