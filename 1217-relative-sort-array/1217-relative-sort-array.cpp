class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        for(int &num : arr1) map[num]++;
        int i = 0;
        for(int &num : arr2){
            while(map[num]-- > 0){
                arr1[i++] = num;
            }
        }
        for(auto &it : map){
            int freq = it.second;
            while(freq > 0){
                arr1[i++] = it.first;
                freq--;
            }
        }
        return arr1;
    }
};