class Solution {
public:
    vector<int> drow = {0, 0, 1, -1};
    vector<int> dcol = {-1, 1, 0, 0};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();
        vector<int> result(k);
        vector<pair<int, int>> sortedQueries;

        for(int i = 0; i < k; i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int tpoints = 0;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        for(auto it : sortedQueries){
            while(!pq.empty() && pq.top().first < it.first){
                int row = pq.top().second.first;
                int col = pq.top().second.second;
                pq.pop();
                tpoints++;

                for(int i = 0; i < 4; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                        visited[nrow][ncol] = 1;
                    }
                }
            }
            result[it.second] = tpoints;
        }

        return result;
    }
};
