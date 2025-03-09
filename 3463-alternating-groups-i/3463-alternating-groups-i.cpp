class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int result = 0, n = colors.size(), count = 0;
        for(int i = 1; i < n+2; i++){
            if(colors[(i-1)%n] != colors[i%n]) count++;
            else count = 0;
            if(count >= 2) result++;
        }
        return result;
    }
};