class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int times = (minutesToTest / minutesToDie + 1);
        while (pow(times, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};
