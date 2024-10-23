class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;
        vector<int> levelSum;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int lvlSum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lvlSum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            levelSum.push_back(lvlSum);
        }

        q.push(root);
        root->val = 0;
        int lvl = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int siblingSum = (node->left != NULL) ? node->left->val : 0;
                siblingSum += (node->right != NULL) ? node->right->val : 0;
                if (node->left) {
                    node->left->val = levelSum[lvl] - siblingSum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum[lvl] - siblingSum;
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return root;
    }
};