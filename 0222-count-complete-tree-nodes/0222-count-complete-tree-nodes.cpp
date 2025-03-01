class Solution {
public:
    int countNodes(TreeNode* root) { 
        if(root == nullptr) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* node){
        int result = 0;
        while(node){
            result++;
            node = node->left;
        }
        return result;
    }

    int findRightHeight(TreeNode* node){
        int result = 0;
        while(node){
            result++;
            node = node->right;
        }
        return result;
    }
};