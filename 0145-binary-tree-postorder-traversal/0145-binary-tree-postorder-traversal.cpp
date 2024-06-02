// TWO STACK APPROACH
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(2N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        vector<int> result;
        while(!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }
        return result;
    }
};
