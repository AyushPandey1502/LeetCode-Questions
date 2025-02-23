class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;
        TreeNode* root =
            constructTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
        return root;
    }

    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructTree(preorder, preStart + 1, preStart + numsLeft,
                                   inorder, inStart, inRoot - 1, inMap);
        root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd,
                                    inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};