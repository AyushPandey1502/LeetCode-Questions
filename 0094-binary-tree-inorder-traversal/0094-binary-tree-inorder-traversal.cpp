// ITERATIVE APPROACH : STACK
// TIME COMPLEXITY : O(N)
// AUXILIARY SPACE COMPLEXITY : O(N) ~ O(HT OF BINARY TREE)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root == NULL) return inorder;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                stack.push(node);
                node = node -> left;
            }else{
                if(stack.empty()) break;
                node = stack.top();
                stack.pop();
                inorder.push_back(node -> val);
                node = node -> right;
            }
        }
        return inorder;
    }
};