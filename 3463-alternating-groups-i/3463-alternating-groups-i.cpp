class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        int N = colors.size();
        for(int i = 1; i < N-1; i++){
            if(colors[i-1] != colors[i] && colors[i] != colors[i+1]){
                count++;
            }
        }
        if(colors[N-2] != colors[N-1] && colors[N-1] != colors[0]){
            count++;
        }
        if(colors[0] != colors[1] && colors[0] != colors[N-1]) count++;
        return count;
    }
};