class Solution {
public:
    int count = 0;
    int result = -1;
    
    void inorderTraversal(TreeNode* root, int k) {
        if (root == NULL) return;
        inorderTraversal(root->left, k);
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorderTraversal(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return result;
    }
};
