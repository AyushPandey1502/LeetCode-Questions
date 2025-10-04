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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<array<int, 3>> cells;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cells.push_back({grid[i][j], i, j});
        }

        sort(cells.begin(), cells.end());
        DisjointSet ds(n * n);
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (auto &cell : cells) {
            int elev = cell[0], row = cell[1], col = cell[2];
            visited[row][col] = 1;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i][0], ncol = col + dir[i][1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && visited[nrow][ncol])
                    ds.unionBySize(row * n + col, nrow * n + ncol);
            }
            if (ds.find(0) == ds.find(n * n - 1)) return elev;
        }
        return -1;
    }
};