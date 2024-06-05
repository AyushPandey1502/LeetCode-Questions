// ONE STACK APPROACH
// TIME COMPLEXITY : O(2N)
// SPACE COMPLEXITY : O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == nullptr) return postorder;
        stack<TreeNode*> st;
        TreeNode* current = root;
        while(current != NULL || !st.empty()){
            if(current != NULL){
                st.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st.top() -> right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    current = temp;
                }
            }
        }
        return postorder;
    }
};
