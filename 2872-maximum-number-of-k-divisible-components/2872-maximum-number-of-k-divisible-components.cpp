class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        vector<int> adjList[n];
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int count = 0;
        dfs(0, -1, adjList, values, k, count);
        return count;
    }

    int dfs(int curr, int parent, vector<int> adjList[], vector<int> &nodeVal, int k, int &count) {
        int sum = 0;
        for (auto ngbr : adjList[curr]) {
            if (ngbr != parent) {
                sum += dfs(ngbr, curr, adjList, nodeVal, k, count);
                sum %= k; 
            }
        }
        sum += nodeVal[curr];
        sum %= k;
        if (sum == 0) count++;
        return sum;
    }
};