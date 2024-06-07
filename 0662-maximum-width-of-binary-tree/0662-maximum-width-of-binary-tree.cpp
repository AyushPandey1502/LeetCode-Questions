// LEVEL ORDER TRAVERSAL
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int result = 0;
        queue<pair<TreeNode*, long long>> q;  
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            long long min = q.front().second;
            long long first = 0, last = 0;
            for (int i = 0; i < size; i++) {
                long long curr_id = q.front().second - min; 
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
                if (node->left)
                    q.push({node->left, 2 * curr_id + 1});
                if (node->right)
                    q.push({node->right, 2 * curr_id + 2});
            }
            result = max(result, static_cast<int>(last - first + 1));
        }
        return result;
    }
};