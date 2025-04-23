class Solution {
public:
    int countLargestGroup(int n) {
        int result = 0, size = 0;
        unordered_map<int, int> map;
        for(int i = 1; i <= n; i++){
            int num = i, sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
            size = max(size, ++map[sum]);
        }
        for(auto it : map){
            if(it.second == size) result++;
        }
        return result;
    }
};