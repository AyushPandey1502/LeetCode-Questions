class Solution {
public:
    bool intersect(unordered_set<int> a, unordered_set<int> b, int k){
        int count = 0;
        for(auto it : b){
            if(a.count(it)) count++;
            if(count >= k) return true;
        }
        return false;
    }

    void dfs(int node, vector<int>& visited, unordered_map<int, vector<int>>& adjList){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]) dfs(it, visited, adjList);
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int result = 0;
        unordered_map<int, vector<int>> adjList;
        int m = properties.size();
        vector<unordered_set<int>> prop(m);
        for(int i = 0 ; i < m; i++) prop[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                if(intersect(prop[i], prop[j], k)){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(m, 0);
        for(int i = 0; i < m; i++){
            if(!visited[i]){
                result++;
                dfs(i, visited, adjList);
            }
        }
        return result;
    }
};