class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
    }

private:
    int calculateDiameter(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }

        int leftHeight = calculateDiameter(node->left, diameter);
        int rightHeight = calculateDiameter(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};