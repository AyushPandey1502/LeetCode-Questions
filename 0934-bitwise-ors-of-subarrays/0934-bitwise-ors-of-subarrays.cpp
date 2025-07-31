class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, curr, next;
        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : curr) {
                next.insert(x | num);
            }
            curr = next;
            result.insert(curr.begin(), curr.end());
        }
        return result.size();
    }
};