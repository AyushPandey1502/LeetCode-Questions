class Solution {
public:
    #define P pair<int, int>
    
    void floydWarshall(int n, vector<vector<int>>& SPM) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (SPM[i][via] != INT_MAX && SPM[via][j] != INT_MAX) {
                        SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                    }
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
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            SPM[u][v] = wt;
            SPM[v][u] = wt;
        }

        floydWarshall(n, SPM);
        return findResult(n, SPM, distanceThreshold);
    }
};