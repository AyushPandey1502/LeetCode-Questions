class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent; 
        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> leaves;

        while (!q.empty()) {
            int size = q.size();
            leaves.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                leaves.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }

        while (leaves.size() > 1) {
            unordered_set<TreeNode*> ancest;
            for (auto node : leaves) {
                node = parent[node]; 
                ancest.insert(node);
            }
            leaves.assign(ancest.begin(), ancest.end());
        }

        return leaves.front();
    }
};
