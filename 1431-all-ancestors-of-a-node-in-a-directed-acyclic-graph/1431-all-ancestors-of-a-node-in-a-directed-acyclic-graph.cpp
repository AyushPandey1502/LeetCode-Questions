class Solution {
public:
    vector<vector<int>> result;

    void dfs(int currNode, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
        visited[currNode] = true;
        for (int& v : adjList[currNode]) {
            if (!visited[v]) {
                dfs(v, adjList, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList; // O(V+E)
        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjList[v].push_back(u); // V --> U
        }

        result.clear();
        result.resize(n);

        for (int u = 0; u < n; u++) { // O(V)
            vector<int> ancestor;
            vector<bool> visited(n, false);
            dfs(u, adjList, visited); // O(V+E)

            for (int i = 0; i < n; i++) { // O(V)
                if (i != u && visited[i]) {
                    ancestor.push_back(i);
                }
            }
            result[u] = ancestor;
        }
        return result;
    }
};
