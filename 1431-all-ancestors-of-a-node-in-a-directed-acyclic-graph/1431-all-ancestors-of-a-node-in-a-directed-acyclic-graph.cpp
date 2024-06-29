// OPTIMAL APPROACH : TOPOLOGICAL SORTED ORDER
// TIME COMPLEXITY : O(V*(V+E))
// SPACE COMPLEXITY : O(V+E)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int, vector<int>> adjList; // O(V+E)
        vector<int> indegree(n, 0);

        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjList[u].push_back(v); // V --> U
            indegree[v]++;
        }

        // TOPOLOGICAL SORTING
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            topoOrder.push_back(currNode);

            for (int& v : adjList[currNode]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<unordered_set<int>> vec(n);
        for (int& node : topoOrder) {
            for (int& v : adjList[node]) {
                vec[v].insert(node); // adding node ancestor
                vec[v].insert(vec[node].begin(),
                              vec[node].end()); // adding ancestor of node
            }
        }
        for (int i = 0; i < n; i++) {
            result[i] = vector<int>(vec[i].begin(), vec[i].end());
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
};
