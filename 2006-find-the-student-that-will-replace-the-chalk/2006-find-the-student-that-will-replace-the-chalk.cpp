class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long totalChalk = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= totalChalk;
        int i = 0;
        while (k >= chalk[i]) {
            k -= chalk[i];
            i = (i + 1) % n;
        }
        return i;
    }
};