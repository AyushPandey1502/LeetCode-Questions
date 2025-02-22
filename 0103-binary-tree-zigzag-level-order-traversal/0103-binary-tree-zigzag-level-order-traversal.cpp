class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while (!q.empty()) {
            int size = q.size();
            deque<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (flag) level.push_back(node->val);
                else level.push_front(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(vector<int>(level.begin(), level.end()));
            flag = !flag;
        }
        return result;
    }
};
