class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = 0;
        calculateDiameter(root, result);
        return result;
    }

    int calculateDiameter(TreeNode* root, int& result){
        if(root == nullptr) return 0;
        int lst = calculateDiameter(root->left, result);
        int rst = calculateDiameter(root->right, result);
        result = max(result, lst + rst);
        return 1 + max(lst, rst);
    }
};