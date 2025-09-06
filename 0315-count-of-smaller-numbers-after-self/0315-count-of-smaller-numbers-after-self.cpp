class Solution {
public:
    int n;
    vector<int> bit; 

    void update(int val, int id){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id){
        int result = 0;
        while(id > 0){
            result += bit[id];
            id -= (id & -id);
        }
        return result;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        bit = vector<int>(n+1, 0);

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++) vec.push_back({nums[i], i});
        sort(vec.begin(), vec.end());

        vector<int> result(n, 0);
        for(auto& [num, id] : vec){
            update(1, id+1);
            result[id] = query(n) - query(id+1);
        }
        return result;
    }
};