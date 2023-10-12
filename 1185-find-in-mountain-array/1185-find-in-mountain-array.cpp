class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        if (n < 3) return -1;

        int start = 0, end = n - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        int peakIndex = start;
        start = 0, end = peakIndex;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (midValue < target) start = mid + 1;
            else end = mid - 1;
        }

        start = peakIndex;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (midValue < target) end = mid - 1;
            else start = mid + 1;
        }

        return -1;
    }
};
