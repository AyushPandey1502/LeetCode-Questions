class Solution {
public:
    unordered_map<int, int> freq;

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    void solve(int i, int j, int n, int m, vector<vector<int>>& mat, int x, int y, int num) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        num = num * 10 + mat[i][j];
        if (num > 10 && isPrime(num)) {
            freq[num]++;
        } 
        solve(i + x, j + y, n, m, mat, x, y, num);
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 8; k++) {
                    solve(i, j, n, m, mat, drow[k], dcol[k], 0);
                }
            }
        }

        int maxFreq = 0;
        int maxFreqNum = -1;
        for (const auto& [num, count] : freq) {
            if (count > maxFreq || (count == maxFreq && num > maxFreqNum)) {
                maxFreq = count;
                maxFreqNum = num;
            }
        }
        return maxFreqNum;
    }
};
