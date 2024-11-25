class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> choices = {{1, 3}, {0, 2, 4}, {1, 5},
                                       {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        unordered_set<string> visited;
        queue<string> q;
        string start = "";

        for (auto it : board) {
            for (auto e : it)
                start += e + '0';
        }
        int result = 0;
        q.push(start);
        visited.insert(start);
        while (q.size()) {
            int n = q.size();
            while (n--) {
                auto current = q.front();
                q.pop();
                if (current == target) return result;
                int possible = current.find('0');
                for (auto it : choices[possible]) {
                    string next = current;
                    swap(next[it], next[possible]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};