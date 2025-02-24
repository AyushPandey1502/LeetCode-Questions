class Solution {
public:
    int result;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;

    bool dfsBob(int node, int time, vector<int>& visited) {
        visited[node] = true;
        bobMap[node] = time;
        if (node == 0) return true;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfsBob(it, time + 1, visited) == true) return true;
            }
        }
        bobMap.erase(node);
        visited[node] = false;
        return false;
    }

    void dfsAlice(int node, int time, vector<int>& visited, int amt, vector<int>& amount) {
        visited[node] = true;
        if (bobMap.count(node) == 0 || time < bobMap[node]) amt += amount[node];
        else if (time == bobMap[node]) amt += amount[node] / 2;
        
        if (adj[node].size() == 1 && node != 0) result = max(result, amt);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfsAlice(it, time + 1, visited, amt, amount);
            }
        }
        visited[node] = false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> visited(n, false);
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfsBob(bob, 0, visited);
        visited.assign(n, false);
        result = INT_MIN;
        dfsAlice(0, 0, visited, 0, amount);
        return result;
    }
};
