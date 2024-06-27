class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int u1 = edges[0][0], v1 = edges[0][1];
        if (edges[1][0] == u1 || edges[1][1] == u1) {
            return u1;
        } else {
            return v1;
        }
    }
};
