class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), result = 0;
        int left = 1, right = *max_element(piles.begin(), piles.end());

        auto check = [&](int mid){
            int count = 0;
            for(int i = 0; i < n; i++){
                count += piles[i] / mid;
                count += (piles[i] % mid != 0 ? 1 : 0);
                if(count > h) return false;
            }
            return count <= h;
        };

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                result = mid;
                right = mid - 1;
            }else left = mid + 1;
        }
        return result;
    }
};