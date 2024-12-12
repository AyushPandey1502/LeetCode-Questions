class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            auto index = max_element(gifts.begin(), gifts.end()); 
            *index = sqrt(*index); 
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
