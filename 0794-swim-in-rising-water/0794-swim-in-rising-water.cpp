class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) mp[grid[i][j]] = {i, j};
        }
        DisjointSet ds(n*n);
        for(int i = 0; i < n*n; i++){
            auto [row, col] = mp[i];
            visited[row][col] = 1;
            for(auto it : dir){
                int nrow = row + it[0], ncol = col + it[1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && visited[nrow][ncol]){
                    int node = row * n + col, adjNode = nrow * n + ncol;
                    ds.unionBySize(node, adjNode);
                }
            }
            if(ds.find(0) == ds.find(n*n-1)) return i;
        }
        return n*n;
    }
};