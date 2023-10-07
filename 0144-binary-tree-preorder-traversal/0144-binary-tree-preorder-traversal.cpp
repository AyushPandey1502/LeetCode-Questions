class Solution {
public:
    void storePreOrder(TreeNode* root, vector<int> &result){
        if(!root) return;
        result.push_back(root->val);
        storePreOrder(root->left, result);
        storePreOrder(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        storePreOrder(root, result);
        return result;
    }
};