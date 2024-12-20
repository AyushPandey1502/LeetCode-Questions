class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (level % 2 == 1) temp.push_back(curr);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (!temp.empty()) {
                int sz = temp.size();
                for (int i = 0; i < sz / 2; i++) {
                    swap(temp[i]->val, temp[sz - i - 1]->val);
                }
            }
            level++;
        }
        return root;
    }
};
