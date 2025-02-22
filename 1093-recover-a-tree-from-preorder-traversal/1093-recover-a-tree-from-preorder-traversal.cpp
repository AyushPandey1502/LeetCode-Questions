class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();
        
        while (i < n) {
            int level = 0, num = 0;
            while (i < n && traversal[i] == '-') {
                level++;
                i++;
            }
            while (i < n && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(num);
            while (st.size() > level) st.pop();
        
            
            if (!st.empty()) {
                if (!st.top()->left) st.top()->left = node;
                else st.top()->right = node;
            }
            st.push(node);
        }
        
        while (st.size() > 1) st.pop();
        return st.top();
    }
};
