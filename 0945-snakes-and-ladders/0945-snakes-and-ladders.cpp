class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatten(n * n + 1, -1);
        int idx = 1;
        bool flag = true;
        for (int i = n - 1; i >= 0; i--) {
            if (flag) {
                for (int j = 0; j < n; ++j) {
                    flatten[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flatten[idx++] = board[i][j];
                }
            }
            flag = !flag;
        }

        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int result = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return result;
                for (int i = 1; i <= 6 && curr + i <= n * n; i++) {
                    int next = curr + i;
                    int dest = flatten[next] == -1 ? next : flatten[next];

                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};
