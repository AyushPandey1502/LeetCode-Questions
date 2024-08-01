class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n+1, INT_MAX);
        pq.push({0, k});
        time[k] = 0;

        while(!pq.empty()){
            int tm = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int ngbr = it.first;
                int edgeTm = it.second;
                if(tm + edgeTm < time[ngbr]){
                    time[ngbr] = tm + edgeTm;
                    pq.push({time[ngbr], ngbr});
                }
            }
        }
        int minTime = 0;
        for(int i = 1; i <= n; i++){
            if(time[i] == INT_MAX) return -1;
            else minTime = max(minTime, time[i]);
        }
        return minTime;
    }
};