class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;

        int postIndex = postorder.size() - 1;
        return constructTree(postorder, inorder, 0, inorder.size() - 1, postIndex, inMap);
    }

    TreeNode* constructTree(vector<int>& postorder, vector<int>& inorder,
                            int inStart, int inEnd, int& postIndex,
                            unordered_map<int, int>& inMap) {
        if (inStart > inEnd || postIndex < 0) return nullptr;

        int rootVal = postorder[postIndex--]; 
        TreeNode* root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];

        root->right = constructTree(postorder, inorder, inRoot + 1, inEnd, postIndex, inMap);
        root->left = constructTree(postorder, inorder, inStart, inRoot - 1, postIndex, inMap);

        return root;
    }
};
