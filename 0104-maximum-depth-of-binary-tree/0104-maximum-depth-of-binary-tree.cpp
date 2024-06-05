// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N) => FOR SKEWED BINARY TREE
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return max(maxDepth(root -> left) + 1, maxDepth(root -> right)+ 1);
    }
};