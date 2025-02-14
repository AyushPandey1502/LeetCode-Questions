class ProductOfNumbers {
public:
    vector<int> prefixProd;
    int size = 0;

    ProductOfNumbers() {
        prefixProd.clear();
        prefixProd.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            prefixProd = {1};
            size = 0;
        }else{
            prefixProd.push_back(num * prefixProd.back());
            size++;
        }
    }
    
    int getProduct(int k) {
        if(k > size) return 0;
        return prefixProd[size] / prefixProd[size - k];
    }
};
