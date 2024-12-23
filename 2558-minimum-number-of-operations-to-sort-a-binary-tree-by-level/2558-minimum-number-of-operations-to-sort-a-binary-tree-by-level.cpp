class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            count += minimumSwapsToSort(temp);
        }
        return count;
    }

    int minimumSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> sortedArr(n);
        for (int i = 0; i < n; i++) {
            sortedArr[i] = {arr[i], i};
        }
        sort(sortedArr.begin(), sortedArr.end());
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedArr[i].second == i) continue;
            int cycleSize = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = sortedArr[j].second;
                cycleSize++;
            }
            if (cycleSize > 1) swaps += cycleSize - 1;
        }
        return swaps;
    }
};
