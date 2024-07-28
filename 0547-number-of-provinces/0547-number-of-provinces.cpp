class Solution {
public:
    void dfs(int source, vector<vector<int>>& adjList, vector<int>& visited){
        visited[source] = 1;
        for(int it : adjList[source]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
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
                dfs(i, adjList, visited);
                result++;
            }
        }
        return result;
    }
};