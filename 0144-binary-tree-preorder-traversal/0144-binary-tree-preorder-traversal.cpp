class Solution {
public:
    vector<int> result;

    void storePreorder(TreeNode* root){
        if(root == nullptr) return;
        result.push_back(root -> val);
        storePreorder(root -> left);
        storePreorder(root -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        storePreorder(root);
        return result;
    }
};