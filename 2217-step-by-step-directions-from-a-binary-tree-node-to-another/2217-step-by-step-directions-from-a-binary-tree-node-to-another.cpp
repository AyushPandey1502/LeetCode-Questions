// LOWEST COMMON ANCESTOR METHOD
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if (root == NULL || root->val == src || root->val == dest) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, src, dest);
        TreeNode* right = lowestCommonAncestor(root->right, src, dest);
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }

    bool findPath(TreeNode* root, int target, string& path) {
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, target, path) == true)
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path) == true)
            return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);
        string lcaToSrc, lcaToDest;

        findPath(lca, startValue, lcaToSrc);
        findPath(lca, destValue, lcaToDest);

        for (int i = 0; i < lcaToSrc.size(); i++) {
            lcaToSrc[i] = 'U';
        }

        return lcaToSrc + lcaToDest;
    }
};