class Solution {
private:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adjLs[v+1];

        // To change adjacency matrix to adjacency list
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i + 1].push_back(j + 1);
                    adjLs[j + 1].push_back(i + 1);
                }
            }
        }
        int vis[v+1];
        for (int i = 0; i <= v; i++) {
            vis[i] = 0;
        }
        int count = 0;
        for(int i = 1; i <= v; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};
