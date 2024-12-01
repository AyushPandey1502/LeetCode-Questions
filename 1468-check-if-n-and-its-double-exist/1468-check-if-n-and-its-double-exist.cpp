class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<float> set;
        for (int i = 0; i < arr.size(); i++) {
            if (set.find(2.0 * arr[i]) != set.end()) return true;  
            if (set.find(static_cast<float>(arr[i]) / 2) != set.end()) return true;  
            set.insert(arr[i]);
        }
        return false;
    }
};
