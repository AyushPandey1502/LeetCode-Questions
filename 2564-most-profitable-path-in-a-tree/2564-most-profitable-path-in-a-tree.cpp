class Solution {
public:
    int result;
    vector<vector<int>> adj;
    vector<int> bobMap; 

    bool dfsBob(int node, int time, vector<int>& visited) {
        visited[node] = true;
        bobMap[node] = time;
        if (node == 0) return true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsBob(neighbor, time + 1, visited)) return true;
            }
        }
        bobMap[node] = -1;
        return false;
    }

    void dfsAlice(int node, int time, int amt, vector<int>& visited, vector<int>& amount) {
        visited[node] = true;
        if (bobMap[node] == -1 || time < bobMap[node]) amt += amount[node]; 
        else if (time == bobMap[node]) amt += amount[node] / 2;

        bool isLeaf = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                isLeaf = false;
                dfsAlice(neighbor, time + 1, amt, visited, amount);
            }
        }
        if (isLeaf) result = max(result, amt);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.assign(n, vector<int>());
        bobMap.assign(n, -1); 
        vector<int> visited(n, false);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfsBob(bob, 0, visited);
        visited.assign(n, false);
        result = INT_MIN;
        dfsAlice(0, 0, 0, visited, amount);
        
        return result;
    }
};
