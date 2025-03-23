class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<unordered_set<int>> propSets(n);
        vector<int> parent(n), rank(n, 1);

        for (int i = 0; i < n; i++) {
            propSets[i] = unordered_set<int>(properties[i].begin(), properties[i].end());
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) swap(rootX, rootY);
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY]) rank[rootY]++;
            }
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rootI = find(i), rootJ = find(j);
                if (rootI == rootJ) continue;
                
                unordered_set<int>& smaller = propSets[i].size() < propSets[j].size() ? propSets[i] : propSets[j];
                unordered_set<int>& larger = propSets[i].size() >= propSets[j].size() ? propSets[i] : propSets[j];

                int common = 0;
                for (int val : smaller) {
                    if (larger.count(val)) {
                        common++;
                        if (common >= k) {
                            unite(i, j);
                            break;
                        }
                    }
                }
            }
        }

        unordered_set<int> result;
        for (int i = 0; i < n; i++) {
            result.insert(find(i));
        }

        return result.size();
    }
};
