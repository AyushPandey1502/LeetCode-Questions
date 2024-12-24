class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> adj1 = buildAdjacencyList(edges1);
        vector<vector<int>> adj2 = buildAdjacencyList(edges2);

        int d1 = getDiameter(0, adj1);
        int d2 = getDiameter(0, adj2);

        int cd = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max({d1, d2, cd});
    }

    vector<vector<int>> buildAdjacencyList(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return adj;
    }

    pair<int, int> bfs(int cur, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;
        q.push({cur, 0});

        pair<int, int> dia = {cur, 0};
        vis[cur] = true;
        while (!q.empty()) {
            auto ft = q.front();
            q.pop();

            for (int& i : adj[ft.first]) {
                if (!vis[i]) {
                    vis[i] = true;
                    q.push({i, ft.second + 1});
                    dia = {i, ft.second + 1};
                }
            }
        }
        return dia;
    }

    int getDiameter(int cur, vector<vector<int>>& adj) {
        auto sp = bfs(cur, adj);
        auto res = bfs(sp.first, adj);
        return res.second;
    }
};
