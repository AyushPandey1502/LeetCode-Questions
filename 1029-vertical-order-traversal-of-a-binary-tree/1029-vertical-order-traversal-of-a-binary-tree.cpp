// INORDER TRAVERSAL
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return {};
        map<int, map<int, multiset<int>>> nodes;
        stack<pair<TreeNode*, pair<int, int>>> stk;
        TreeNode* current = root;
        int x = 0;
        int y = 0;

        while (current != NULL || !stk.empty()) {
            while (current != NULL) {
                stk.push({current, {x, y}});
                current = current->left;
                x--;
                y++;
            }
            auto p = stk.top();
            stk.pop();
            current = p.first;
            x = p.second.first;
            y = p.second.second;
            nodes[x][y].insert(current->val);
            current = current->right;
            x++;
            y++;
        }

        vector<vector<int>> result;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
