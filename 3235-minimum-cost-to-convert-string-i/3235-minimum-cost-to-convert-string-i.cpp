class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        if (n != target.size()) return -1;

        vector<vector<long long>> graph(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }
        
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = min(graph[u][v], (long long)cost[i]);
        }
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
        
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            if (source[i] != target[i]) {
                int s = source[i] - 'a';
                int t = target[i] - 'a';
                if (graph[s][t] == LLONG_MAX) return -1;
                result += graph[s][t];
            }
        }
        return result;
    }
};
