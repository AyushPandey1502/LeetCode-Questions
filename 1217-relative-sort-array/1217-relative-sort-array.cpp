class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> map;
        for(int i = 0; i < arr2.size(); i++){
            map[arr2[i]] = i;
        }
        for(int &num : arr1){
            if(!map.count(num)){
                map[num] = INT_MAX;
            }
        }
        auto lambda = [&](int &num1, int &num2){
            if(map[num1] == map[num2]){
                return num1 < num2;
            }
            return map[num1] < map[num2];
        };
        sort(arr1.begin(), arr1.end(), lambda);
        return arr1;
    }
};