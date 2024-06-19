class Solution {
public:
    int canMakeBouq(vector<int> &bloomDay, int mid, int k){
        int numBouq = 0;
        int count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid) count++;
            else count = 0;
            if(count == k){
                numBouq++;
                count = 0;
            }
        }
        return numBouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int startDay = 0;
        int endDay = *max_element(begin(bloomDay), end(bloomDay));

        int minDays = -1;
        while(startDay <= endDay){
            int mid = startDay + (endDay - startDay) / 2;
            if(canMakeBouq(bloomDay, mid, k) >= m){
                minDays = mid;
                endDay = mid-1;
            }else{
                startDay = mid+1;
            }
        }
        return minDays;
    }
};