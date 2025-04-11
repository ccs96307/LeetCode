class ProductOfNumbers {
public:
    vector<int> vec;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.emplace_back(num);   
    }
    
    int getProduct(int k) {
        return std::accumulate(vec.end() - k, vec.end(), 1, std::multiplies<int>());
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

