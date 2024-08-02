// TARJAN'S ALGORITHM

class Solution {
public:
    vector<vector<int>> bridges;
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& time, vector<int>& lowTm) {
        visited[node] = 1;
        time[node] = lowTm[node] = timer++;

        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!visited[it]) {
                dfs(it, node, adj, visited, time, lowTm);
                lowTm[node] = min(lowTm[node], lowTm[it]);
                if (lowTm[it] > time[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                lowTm[node] = min(lowTm[node], time[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0), time(n, 0), lowTm(n, 0);
        dfs(0, -1, adj, visited, time, lowTm);
        return bridges;
    }
};
