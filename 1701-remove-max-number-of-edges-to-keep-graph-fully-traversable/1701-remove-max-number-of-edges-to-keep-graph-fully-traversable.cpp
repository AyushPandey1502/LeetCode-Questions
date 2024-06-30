class DSU {
    private:
        vector<int> parent;
        vector<int> rank;
        int components;

    public:
        DSU(int n) : parent(n + 1), rank(n + 1, 0), components(n) {
            for (int i = 1; i <= n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (x == parent[x]) 
                return x;
            return parent[x] = find(parent[x]);
        }

        bool unionSet(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return false;

            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
            components--;
            return true;
        }

        bool isSingle() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });

        DSU Alice(n);
        DSU Bob(n);
        int addedEdge = 0;

        for (const auto& edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3) {
                bool add = Alice.unionSet(u, v) | Bob.unionSet(u, v);
                if (add) addedEdge++;
            } else if (type == 2) {
                if (Bob.unionSet(u, v)) addedEdge++;
            } else {
                if (Alice.unionSet(u, v)) addedEdge++;
            }
        }
        if (Alice.isSingle() && Bob.isSingle()) {
            return edges.size() - addedEdge;
        }

        return -1;
    }
};
