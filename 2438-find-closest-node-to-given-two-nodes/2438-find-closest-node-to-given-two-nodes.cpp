class Solution {
public:
    void bfs(int src, vector<int>& edges, vector<int>& dist) {
        int n = edges.size();
        queue<int> q;
        q.push(src);

        vector<bool> visit(n, false);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (visit[node]) continue;
            visit[node] = true;

            int ngbr = edges[node];
            if (ngbr != -1 && !visit[ngbr]) {
                dist[ngbr] = 1 + dist[node];
                q.push(ngbr);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int result = -1;
        int minDistTillNow = numeric_limits<int>::max();

        for (int curr = 0; curr < n; curr++) {
            if (dist1[curr] != numeric_limits<int>::max() && dist2[curr] != numeric_limits<int>::max()) {
                int maxDist = max(dist1[curr], dist2[curr]);
                if (maxDist < minDistTillNow) {
                    minDistTillNow = maxDist;
                    result = curr;
                }
            }
        }

        return result;
    }
};
