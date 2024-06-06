// RECURSIVE APPROACH
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        modifiedPreorder(root, 0, result);
        return result;
    }

    void modifiedPreorder(TreeNode* root, int level, vector<int> &result){
        if(root == NULL) return;
        if(level == result.size()) result.push_back(root -> val);
        modifiedPreorder(root -> right, level + 1, result);
        modifiedPreorder(root -> left, level + 1, result);
    }
};