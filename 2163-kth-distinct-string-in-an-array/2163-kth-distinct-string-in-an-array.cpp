class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (auto it : arr) {
            map[it]++;
        }
        int count = 0;
        string result;
        for (int i = 0; i < arr.size(); i++) {
            if (map[arr[i]] == 1) {
                count++;
            }
            if (count == k) {
                result = arr[i];
                break;
            }
        }
        return result;
    }
};