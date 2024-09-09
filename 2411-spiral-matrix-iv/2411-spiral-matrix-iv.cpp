class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int top = 0, left = 0;
        int bottom = m - 1, right = n - 1;

        while (head) {
            for (int i = left; i <= right && head; i++) {
                result[top][i] = head->val;
                head = head->next;
            }
            top++;
            for (int i = top; i <= bottom && head; i++) {
                result[i][right] = head->val;
                head = head->next;
            }
            right--;
            for (int i = right; i >= left && head; i--) {
                result[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;
            for (int i = bottom; i >= top && head; i--) {
                result[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        return result;
    }
};
