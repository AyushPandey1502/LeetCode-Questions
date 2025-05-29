class Solution {
public:
    int dfs(int node, int parent, int depth,
            const vector<vector<int>>& children, vector<int>& color) {
        color[node] = depth % 2;
        int result = (color[node] == 0) ? 1 : 0;
        for (int child : children[node]) {
            if (child == parent) continue;
            result += dfs(child, node, depth + 1, children, color);
        }
        return result;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        color.resize(n);
        int countColor0 = dfs(0, -1, 0, children, color);
        int countColor1 = n - countColor0;
        return {countColor0, countColor1};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<int> color1(n), color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = count1[color1[i]] + max(count2[0], count2[1]);
        }
        return result;
    }
};
