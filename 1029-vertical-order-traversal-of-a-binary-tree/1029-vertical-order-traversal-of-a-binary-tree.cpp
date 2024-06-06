// TIME COMPLEXITY : O(N*LOG(N))
// SPACE COMPLEXITY : O(N)
// INORDER TRAVERSAL

class Solution {
public:
    void inorderTraversal(TreeNode* node, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (!node) return;
        inorderTraversal(node->left, x - 1, y + 1, nodes);
        nodes[x][y].insert(node->val);
        inorderTraversal(node->right, x + 1, y + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        inorderTraversal(root, 0, 0, nodes);
        vector<vector<int>> result;
        for (const auto& p : nodes) {
            vector<int> col;
            for (const auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        return result;
    }
};
