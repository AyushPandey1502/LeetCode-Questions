class KthLargest {
public:
    int k;
    multiset<int, less<int>> container; 
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) {
            container.insert(x);
            if (container.size() > k) {
                container.erase(container.begin());
            }
        }
    }

    int add(int val) {
        container.insert(val);
        if (container.size() > k) {
            container.erase(container.begin());
        }
        return *(container.begin());
    }
};