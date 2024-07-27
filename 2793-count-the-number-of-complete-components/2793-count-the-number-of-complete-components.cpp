class Solution {
public:
    void bfs(int n, vector<vector<int>>& adjList, vector<int> &visited, int s, int &nodeCount, int &edgeCount){
        queue<int> q;
        q.push(s);
        visited[s] = 1;
        nodeCount = 0;
        edgeCount = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nodeCount++;
            for(auto it : adjList[node]){
                edgeCount++;
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(const auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int result = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int nodeCount = 0, edgeCount = 0;
                bfs(n, adjList, visited, i, nodeCount, edgeCount);
                edgeCount /= 2;
                if(edgeCount == nodeCount * (nodeCount - 1) / 2) {
                    result++;
                }
            }
        }
        return result;
    }
};
