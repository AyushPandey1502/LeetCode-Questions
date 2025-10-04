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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0, count = 0;
        for(auto it : connections){
            int u = it[0], v = it[1];
            if(ds.find(u) == ds.find(v)) extra++;
            ds.unionBySize(u, v);
        }
        unordered_set<int> seen;
        for(int i = 0; i < n; i++){
            int parent = ds.find(i);
            if(seen.find(parent) == seen.end()){
                seen.insert(parent);
                count++;
            }
        }
        if((count-1) <= extra) return count-1;
        return -1;
    }
};