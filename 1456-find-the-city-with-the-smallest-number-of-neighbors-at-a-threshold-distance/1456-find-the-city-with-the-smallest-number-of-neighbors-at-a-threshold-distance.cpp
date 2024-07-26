class Solution {
public:
    #define P pair<int, int>

    void bellmanFord(int n, vector<vector<int>>& edges, vector<int>& result, int S) {
        fill(result.begin(), result.end(), INT_MAX);
        result[S] = 0;
        
        for(int i = 0; i < n; i++){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(result[u] != INT_MAX && result[u] + wt < result[v]){
                    result[v] = result[u] + wt;
                }
                if(result[v] != INT_MAX && result[v] + wt < result[u]){
                    result[u] = result[v] + wt;
                }
            }
        }
    }

    int findResult(int n, vector<vector<int>>& SPM, int DT) {
        int result = 0;
        int leastReachCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && SPM[i][j] <= DT) {
                    count++;
                }
            }
            if (count <= leastReachCount) {
                leastReachCount = count;
                result = i;
            }
        }
        return result;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            SPM[i][i] = 0;
        }
        unordered_map<int, vector<P>> adj;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, SPM[i], i);
        }
        return findResult(n, SPM, distanceThreshold);
    }
};