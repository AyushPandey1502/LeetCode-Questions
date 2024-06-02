// ITERATIVE METHOD
// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n) ~ O(Height of Binary Tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            if(node -> right != NULL) stack.push(node -> right);
            if(node -> left != NULL) stack.push(node -> left);
            preorder.push_back(node -> val);
        }
        return preorder;
    }
};