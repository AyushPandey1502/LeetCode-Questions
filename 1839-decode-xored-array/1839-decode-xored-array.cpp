class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr;
        arr.push_back(first);
        for(int i = 1; i < encoded.size() + 1; i++){
            arr.push_back(arr[i-1] ^ encoded[i-1]);
        }
        return arr;
    }
};
