class Solution {
public:
    void dfs(int source, vector<vector<int>>& adj, vector<int>& visited) {
        visited[source] = 1;
        for (int i = 0; i < adj[source].size(); ++i) {
            if (adj[source][i] == 1 && !visited[i]) {
                dfs(i, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V, 0);
        int result = 0;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                result++;
                dfs(i, isConnected, visited);
            }
        }
        return result;
    }
};