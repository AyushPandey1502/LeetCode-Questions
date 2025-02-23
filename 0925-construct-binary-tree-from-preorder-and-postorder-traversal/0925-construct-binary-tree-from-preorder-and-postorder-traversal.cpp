class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> postMap;
        for(int i = 0; i < n; i++) postMap[postorder[i]] = i;
        TreeNode* root = constructTree(preorder, 0, n-1, postorder, 0, n-1, postMap);
        return root;
    }

    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& postMap){
        if(preStart > preEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        int numsLeft = postMap[preorder[preStart + 1]] - postStart + 1;

        root->left = constructTree(preorder, preStart + 1, numsLeft + preStart, postorder, postStart, postStart + numsLeft - 1, postMap); 
        root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, postorder, postStart + numsLeft, postEnd - 1, postMap);
        return root;
    }
};