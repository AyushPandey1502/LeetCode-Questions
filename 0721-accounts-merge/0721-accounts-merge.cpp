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

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) mpp[mail] = i;
                else ds.unionBySize(i, mpp[mail]);
            }
        }
        vector<vector<string>> mergedMails(n);
        for(auto it : mpp){
            string mail = it.first;
            int node = ds.find(it.second);
            mergedMails[node].push_back(mail);
        }
        vector<vector<string>> result;
        for(int i = 0; i < n; i++){
            if(mergedMails[i].size() == 0) continue;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedMails[i]) temp.push_back(it);
            result.push_back(temp);
        }
        return result;
    }
};