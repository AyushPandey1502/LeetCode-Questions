class Solution {
public:
    int MOD = 1e9 + 7;
    using P = pair<long long, int>;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edgeWt = it.second;
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if (dis + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};