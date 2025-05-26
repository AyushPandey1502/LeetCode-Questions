class Solution {
public:
    int dfs(int node, const string &colors, vector<vector<int>> &adj,
            vector<vector<int>> &colorCount, vector<int> &state) {
        if (state[node] == 1) return INT_MAX;
        if (state[node] == 2) return colorCount[node][colors[node] - 'a'];

        state[node] = 1;

        for (int neighbor : adj[node]) {
            if (dfs(neighbor, colors, adj, colorCount, state) == INT_MAX) return INT_MAX;
            for (int c = 0; c < 26; ++c)
                colorCount[node][c] = max(colorCount[node][c], colorCount[neighbor][c]);
        }

        colorCount[node][colors[node] - 'a']++;
        state[node] = 2;

        return colorCount[node][colors[node] - 'a'];
    }

    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> colorCount(n, vector<int>(26));
        vector<int> state(n);

        for (const auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);

        int result = 0;
        for (int i = 0; i < n; i++) {
            int val = dfs(i, colors, adj, colorCount, state);
            if (val == INT_MAX) return -1;
            result = max(result, val);
        }
        return result;
    }
};
