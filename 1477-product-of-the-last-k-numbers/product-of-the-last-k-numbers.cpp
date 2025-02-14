class ProductOfNumbers {
public:
    vector<int>ans;
    ProductOfNumbers() {
        // ans.clear();
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        for(int i = ans.size()-k; i<ans.size(); i++){
            product *= ans[i];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */