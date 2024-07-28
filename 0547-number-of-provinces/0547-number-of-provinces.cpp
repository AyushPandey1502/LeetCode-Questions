class Solution {
public:
    void bfs(int source, vector<vector<int>>& adjList, vector<int>& visited){
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it : adjList[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);\
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int result = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                bfs(i, adjList, visited);
                result++;
            }
        }
        return result;
    }
};