class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return {};

        // Map to store the nodes (x-coordinate -> (y-coordinate -> sorted node values))
        map<int, map<int, multiset<int>>> nodes;

        // Stack to store nodes along with their coordinates and a visited flag
        stack<pair<TreeNode*, pair<pair<int, int>, bool>>> stk;
        stk.push({root, {{0, 0}, false}});
        
        while (!stk.empty()) {
            auto p = stk.top();
            stk.pop();
            TreeNode* node = p.first;
            int x = p.second.first.first;
            int y = p.second.first.second;
            bool visited = p.second.second;

            if (node == NULL) continue;

            if (visited) {
                // If the node has been visited, process it
                nodes[x][y].insert(node->val);
            } else {
                // Push the current node back onto the stack with the visited flag set to true
                stk.push({node, {{x, y}, true}});
                // Push the right child, then the left child onto the stack
                stk.push({node->right, {{x + 1, y + 1}, false}});
                stk.push({node->left, {{x - 1, y + 1}, false}});
            }
        }

        // Building the result from the map
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
