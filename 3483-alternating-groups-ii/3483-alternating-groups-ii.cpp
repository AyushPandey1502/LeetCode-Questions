class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (n < k) return 0;
        int count = 0;
        int alternating = 0;
        for (int i = 0; i < k - 1; ++i) {
            if (colors[i] != colors[i + 1]) alternating++;
        }
        for (int i = 0; i < n; ++i) {
            int start = i;
            int end = (i + k - 1) % n;
            
            if (alternating == k - 1) count++;
            if (colors[start] != colors[(start + 1) % n]) alternating--;
            if (colors[end] != colors[(end + 1) % n]) alternating++;
        }
        
        return count;
    }
};