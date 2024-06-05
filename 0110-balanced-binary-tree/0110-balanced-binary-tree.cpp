class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int leftHt = height(root -> left);
        int rightHt = height(root -> right);

        if(abs(leftHt - rightHt) > 1) return false;
        bool left = isBalanced(root -> left);
        bool right = isBalanced(root -> right);
        if(left == false || right == false) return false;
        return true;
    }

    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);
        return 1 + max(lh, rh);
    }
};