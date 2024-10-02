class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> set(arr.begin(), arr.end());
        int count = 1;
        unordered_map<int, int> rank;
        for(int it : set) rank[it] = count++;
        for(int i = 0; i < arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};