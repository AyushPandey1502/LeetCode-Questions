class Solution {
public:
    int checkBalance(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHt = checkBalance(root -> left);
        if(leftHt == -1) return -1;
        int rightHt = checkBalance(root -> right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt) > 1) return -1;
        return 1 + max(leftHt, rightHt);
    }
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
};