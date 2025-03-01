class Solution {
public:
    vector<int> result;
    unordered_map<TreeNode*, TreeNode*> parent;

    void findNodes(TreeNode* root, TreeNode* prev, int k) {
        if (!root || k < 0) return;
        if (k == 0) {
            result.push_back(root->val);
            return;
        }
        if (prev != parent[root]) findNodes(parent[root], root, k - 1);
        if (prev != root->left) findNodes(root->left, root, k - 1);
        if (prev != root->right) findNodes(root->right, root, k - 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        result.clear();
        parent.clear();

        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        findNodes(target, nullptr, k);
        return result;
    }
};