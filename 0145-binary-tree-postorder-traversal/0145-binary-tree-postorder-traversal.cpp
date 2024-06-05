// PREORDER, INORDER AND POSTORDER USING SINGLE STACK
// TIME COMPLEXITY : O(3N)
// SPACE COMPLEXITY : O(3N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> preorder, inorder, postorder;
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        if (root == NULL)
            return postorder;
        while (!stack.empty()) {
            auto it = stack.top();
            stack.pop();

            // PREORDER
            if (it.second == 1) {
                preorder.push_back(it.first->val);
                it.second++;
                stack.push(it);
                if (it.first->left != NULL)
                    stack.push({it.first->left, 1});
            }
            // INORDER
            else if (it.second == 2) {
                inorder.push_back(it.first->val);
                it.second++;
                stack.push(it);
                if (it.first->right != NULL)
                    stack.push({it.first->right, 1});
            }
            // POSTORDER
            else {
                postorder.push_back(it.first->val);
            }
        }
        return postorder;
    }
};