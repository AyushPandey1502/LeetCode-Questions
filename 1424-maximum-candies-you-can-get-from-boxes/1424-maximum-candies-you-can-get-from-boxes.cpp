class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false), hasBox(n, false), visited(n, false);
        queue<int> q;
        int result = 0;
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box]) {
                q.push(box);
                visited[box] = true;
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            result += candies[box];
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    if (hasBox[key] && !visited[key]) {
                        q.push(key);
                        visited[key] = true;
                    }
                }
            }
            for (int it : containedBoxes[box]) {
                hasBox[it] = true;
                if ((status[it] || hasKey[it]) && !visited[it]) {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        return result;
    }
};
