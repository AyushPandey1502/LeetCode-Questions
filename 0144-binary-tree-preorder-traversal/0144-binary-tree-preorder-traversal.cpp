// Time Complexity : O(n)
// Space Complexity : O(n)
class Solution {
public:
    void storePreorder(TreeNode* root, vector<int> &result){
        if(root == nullptr) return;
        result.push_back(root -> val);
        storePreorder(root -> left, result);
        storePreorder(root -> right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        storePreorder(root, result);
        return result;
    }
};