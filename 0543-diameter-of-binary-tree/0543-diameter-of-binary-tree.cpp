class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

    int calculateDiameter(TreeNode* root, int &diameter){
        if(root == NULL) return 0;
        int lh = calculateDiameter(root -> left, diameter);
        int rh = calculateDiameter(root -> right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};