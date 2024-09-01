class Solution {
public:
    void rightSideView(TreeNode* root, int level, vector<int>& result){
        if(root == nullptr) return;
        if(level == result.size()) result.push_back(root -> val);
        rightSideView(root -> right, level + 1, result);
        rightSideView(root -> left, level + 1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideView(root, 0, result);
        return result;
    }
};