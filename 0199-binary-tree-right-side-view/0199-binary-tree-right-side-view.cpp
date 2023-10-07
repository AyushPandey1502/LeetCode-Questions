class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* lastNode = nullptr; 

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                lastNode = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(lastNode->val);
        }

        return result;
    }
};
