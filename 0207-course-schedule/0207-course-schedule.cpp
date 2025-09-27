class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDeg[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it : adj[node]){
                if(--inDeg[it] == 0) q.push(it);
            }
        }
        return (count == numCourses);
    }
};