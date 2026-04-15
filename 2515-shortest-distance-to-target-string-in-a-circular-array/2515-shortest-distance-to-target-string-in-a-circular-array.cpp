class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int result = words.size(), n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                result = min(result, min(dist, n - dist));
            }
        }
        return result < n ? result : -1;
    }
};