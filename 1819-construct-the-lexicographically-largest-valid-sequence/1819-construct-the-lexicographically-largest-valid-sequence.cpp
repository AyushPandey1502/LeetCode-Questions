class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> visited(n + 1, false);
        backtrack(result, visited, n, 0);
        return result;
    }

private:
    bool backtrack(vector<int>& result, vector<bool>& visited, int n, int index) {
        while (index < result.size() && result[index] != 0) index++;
        if (index == result.size()) return true;

        for (int i = n; i >= 1; i--) {
            if (visited[i]) continue;
            
            int secondIndex = (i > 1) ? index + i : index;
            if (secondIndex < result.size() && result[secondIndex] == 0) {
                result[index] = i;
                if (i > 1) result[secondIndex] = i;
                visited[i] = true;
                if (backtrack(result, visited, n, index + 1)) return true;
                result[index] = 0;
                if (i > 1) result[secondIndex] = 0;
                visited[i] = false;
            }
        }
        return false;
    }
};
