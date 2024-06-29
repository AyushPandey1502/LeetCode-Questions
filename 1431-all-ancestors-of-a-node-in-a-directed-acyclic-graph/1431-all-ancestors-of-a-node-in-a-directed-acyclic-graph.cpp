// BETTER APPROACH 2 : REVERSE DIRECTION OF ARROWS TO FIND ANCESTOR
// TIME COMPLEXITY : O(V*(V+E))
// SPACE COMPLEXITY : O(V+E)
class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adjList,
             vector<bool>& visited) {
        visited[u] = true;
        for (int& v : adjList[u]) {
            if(visited[v] != true){
                dfs(v, adjList, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> adjList; // O(V+E)
        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjList[v].push_back(u); // V --> U
        }

        for (int u = 0; u < n; u++) { // O(V)
            vector<int> ancestor;
            vector<bool> visited(n, false);
            dfs(u, adjList, visited); // O(V+E)

            for (int i = 0; i < n; i++) { // O(V)
                if (i == u) continue;
                if (visited[i] == true) ancestor.push_back(i);
            }
            result.push_back(ancestor);
        }
        return result;
    }
};
