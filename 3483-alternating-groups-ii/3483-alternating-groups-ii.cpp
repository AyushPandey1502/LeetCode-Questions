class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), result = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < k-1; j++){
                if(colors[(i+j)%n] != colors[(i+j+1)%n]) count++;
            }
            if(count == k-1) result++;
        }
        return result;
    }
};