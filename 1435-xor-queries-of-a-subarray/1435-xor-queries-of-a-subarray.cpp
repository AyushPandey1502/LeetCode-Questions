class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXOR;
        int XOR = 0;
        for (int i = 0; i < arr.size(); i++) {
            XOR = XOR ^ arr[i];
            prefixXOR.push_back(XOR);
        }
        int n = queries.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            if (left == 0) {
                result[i] = prefixXOR[right];
            } else {
                result[i] = prefixXOR[left - 1] ^ prefixXOR[right];
            }
        }
        return result;
    }
};
