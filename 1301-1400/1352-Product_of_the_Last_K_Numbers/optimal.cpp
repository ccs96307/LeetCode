class ProductOfNumbers {
public:
    std::vector<int> vec;

    ProductOfNumbers() {
        vec.emplace_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            vec.clear();
            vec.emplace_back(1);
        }
        else {
            vec.emplace_back(vec.back() * num);   
        }
    }
    
    int getProduct(int k) {
        // It means the interval has 0
        if (k >= vec.size()) {
            return 0;
        }
        
        return vec.back() / vec[vec.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

