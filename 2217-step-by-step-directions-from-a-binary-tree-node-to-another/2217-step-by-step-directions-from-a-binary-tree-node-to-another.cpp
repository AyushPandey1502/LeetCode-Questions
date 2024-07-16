// SLIGHTY OPTIMIZED
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

class Solution {
public:
    bool findPath(TreeNode* root, int target, string& path) {
        if (root == NULL) {
            return false;
        }
        if (root->val == target) {
            return true;
        }
        path.push_back('L');
        if (findPath(root->left, target, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc, rootToDest;

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDest);

        int i = 0;
        while (i < rootToSrc.size() && i < rootToDest.size() && rootToSrc[i] == rootToDest[i]) {
            i++;
        }

        string result;
        for (int j = i; j < rootToSrc.size(); j++) {
            result += 'U';
        }
        for (int j = i; j < rootToDest.size(); j++) {
            result += rootToDest[j];
        }

        return result;
    }
};
