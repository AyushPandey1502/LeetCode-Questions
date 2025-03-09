class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int result = 0, n = colors.size(), count = 0;
        for(int i = 1; i < n+k-1; i++){
            if(colors[(i-1)%n] != colors[i%n]) count++;
            else count = 0;
            if(count >= k-1) result++;
        }
        return result;
    }
};