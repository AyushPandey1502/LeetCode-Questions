class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for (char ch : s) {
            if (ch == 'b') {
                bCount++;
            } else if (ch == 'a') {
                if (bCount > 0) {
                    deletions++;
                    bCount--;
                }
            }
        }
        return deletions;
    }
};
