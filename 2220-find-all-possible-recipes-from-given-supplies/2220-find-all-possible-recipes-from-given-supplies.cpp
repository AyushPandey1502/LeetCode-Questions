class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& s) {
        unordered_set<string> sup(s.begin(), s.end());
        unordered_map<string, int> rIdx;
        unordered_map<string, vector<string>> dep;
        
        for (int i = 0; i < r.size(); i++) rIdx[r[i]] = i;
        vector<int> deg(r.size(), 0);
        for (int i = 0; i < r.size(); i++) {
            for (string& x : ing[i]) {
                if (!sup.count(x)) {
                    dep[x].push_back(r[i]);
                    deg[i]++;
                }
            }
        }
        
        queue<int> q;
        for (int i = 0; i < r.size(); i++) {
            if (deg[i] == 0) q.push(i);
        }
        
        vector<string> result;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            result.push_back(r[i]);
            
            if (!dep.count(r[i])) continue;
            
            for (string& x : dep[r[i]]) {
                if (--deg[rIdx[x]] == 0) q.push(rIdx[x]);
            }
        }
        return result;
    }
};