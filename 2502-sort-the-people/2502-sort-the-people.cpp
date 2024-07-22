class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices(names.size());
        for (int i = 0; i < indices.size(); i++) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return heights[a] > heights[b];
        });
        vector<string> sortedNames(names.size());
        for (int i = 0; i < indices.size(); i++) {
            sortedNames[i] = names[indices[i]];
        }
        return sortedNames;
    }
};
