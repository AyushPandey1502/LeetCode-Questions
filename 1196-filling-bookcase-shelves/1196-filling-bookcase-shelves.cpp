class Solution {
public:
    int n;
    int WIDTH;
    vector<vector<int>> memo;

    int arrangeBooks(vector<vector<int>>& books, int i, int remainW, int maxHt) {
        if (i >= n) {
            return maxHt;
        }

        if (memo[i][remainW] != -1) {
            return memo[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;
        if (bookW <= remainW) { 
            keep = arrangeBooks(books, i + 1, remainW - bookW, max(maxHt, bookH));
        }
        skip = maxHt + arrangeBooks(books, i + 1, WIDTH - bookW, bookH);

        return memo[i][remainW] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        WIDTH = shelfWidth;
        memo = vector<vector<int>>(n, vector<int>(shelfWidth + 1, -1));
        int remainW = shelfWidth;
        return arrangeBooks(books, 0, remainW, 0);
    }
};