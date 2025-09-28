class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        auto bfs = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()) {
                int node = q.front(); q.pop();
                for(int neighbor : graph[node]) {
                    if(color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if(color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
            return true;
        };

        for(int i = 0; i < V; i++) {
            if(color[i] == -1 && !bfs(i)) return false;
        }
        return true;
    }
};
