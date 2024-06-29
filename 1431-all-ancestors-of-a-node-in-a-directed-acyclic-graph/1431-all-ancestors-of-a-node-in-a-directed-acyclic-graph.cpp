class Solution {
public:
    vector<vector<int>> result;
    void dfs(int ancestor, unordered_map<int, vector<int>>& adjList, int currNode) {
        for (int& ngbr : adjList[currNode]) {
            if (result[ngbr].empty() || result[ngbr].back() != ancestor) {
                result[ngbr].push_back(ancestor);
                dfs(ancestor, adjList, ngbr);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjList[u].push_back(v);
        }
        
        result.resize(n);
        
        for (int i = 0; i < n; i++) {
            int ancestor = i;
            dfs(ancestor, adjList, i);
        }
        return result;
    }
};
