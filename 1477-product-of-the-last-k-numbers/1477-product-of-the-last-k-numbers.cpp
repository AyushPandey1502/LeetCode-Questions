class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {
        nums.clear();
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1, n = nums.size();
        for(int i = n-1; i >= n-k; i--){
            prod *= nums[i];
            if(prod == 0) return prod;
        }
        return prod;
    }
};
