class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if(d > dist[node]) continue;

            for(auto it : adj[node]){
                if(it.second + d < dist[it.first]){
                    dist[it.first] = it.second + d;
                    ways[it.first] = ways[node];
                    pq.push({dist[it.first], it.first});
                }else if(it.second + d == dist[it.first]){
                    ways[it.first] = (ways[it.first] + ways[node]) % MOD;
                }
            }
        }
        return ways.back() % MOD;
    }
};