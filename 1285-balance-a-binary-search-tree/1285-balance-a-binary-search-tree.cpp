class Solution {
public:
    void inorderTrav(TreeNode* root, vector<int> &inorder) {
        if (root == NULL) return;
        inorderTrav(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrav(root->right, inorder);  
    }

    TreeNode* formBalBST(int l, int r, const vector<int> &inorder) { 
        if (l > r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = formBalBST(l, mid - 1, inorder);
        root->right = formBalBST(mid + 1, r, inorder); 
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTrav(root, inorder);
        int n = inorder.size();
        return formBalBST(0, n - 1, inorder);
    }
};
