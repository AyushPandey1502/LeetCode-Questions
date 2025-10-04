class Solution {
public:
    vector<vector<int>> bridges;
    int timer = 1;

    void dfs(int node, int parent, vector<int>& visited, vector<int> adj[],
             vector<int>& time, vector<int>& lwTm) {

        visited[node] = 1;
        time[node] = lwTm[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (visited[it]) lwTm[node] = min(lwTm[node], time[it]);
            else {
                dfs(it, node, visited, adj, time, lwTm);
                lwTm[node] = min(lwTm[node], lwTm[it]);
                if (lwTm[it] > time[node]) bridges.push_back({node, it});
            }
        }
    }

    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E) {
        vector<int> adj[V];
        for (auto &it : E) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(V, 0), time(V, 0), lwTm(V, 0);
        dfs(0, -1, visited, adj, time, lwTm);
        return bridges;
    }
};
