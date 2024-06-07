// BRUTE FORCE APPROACH
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*> &arr){
        if(root == NULL) return false;
        arr.push_back(root);
        if(root == p) return true;
        if(getPath(root->left, p, arr) || getPath(root->right, p, arr)) return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        int i = 0;
        while(i < path1.size() && i < path2.size()){
            if(path1[i] != path2[i]) return path1[i-1];
            i++;
        }
        return path1[i-1];
    }
};