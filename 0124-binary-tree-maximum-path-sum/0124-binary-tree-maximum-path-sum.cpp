class Solution {
public:
    int maxSum = INT_MIN;;
    int maxPathSum(TreeNode* root) {
        maxPathDown(root);
        return maxSum;
    }

    int maxPathDown(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = max(0, maxPathDown(root -> left));
        int rightSum = max(0, maxPathDown(root -> right));
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }
};