class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;
        for(int i = 0; i < postorder.size(); i++) postMap[postorder[i]] = i;
        return constructTree(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postMap);
    }

private:
    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd, 
                            vector<int>& postorder, int postStart, int postEnd, 
                            unordered_map<int, int>& postMap) {
        if (preStart > preEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;
        
        int leftChildIdx = postMap[preorder[preStart + 1]];
        int numsLeft = leftChildIdx - postStart + 1;
        
        root->left = constructTree(preorder, preStart + 1, preStart + numsLeft, 
                                   postorder, postStart, leftChildIdx, postMap);
        root->right = constructTree(preorder, preStart + numsLeft + 1, preEnd, 
                                    postorder, leftChildIdx + 1, postEnd - 1, postMap);
        
        return root;
    }
};