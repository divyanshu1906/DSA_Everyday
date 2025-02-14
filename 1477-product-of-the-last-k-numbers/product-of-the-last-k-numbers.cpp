class ProductOfNumbers {
public:
    vector<int>ans;
    int n;
    ProductOfNumbers() {
        ans.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            ans = {};
            n=0;
        }
        else{
            if(!ans.empty()){
                ans.push_back(ans[n-1]*num);
            }
            else {
                ans.push_back(num);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k>n) return 0;
        else if(k==n) return ans[n-1];
        
        return ans[n-1]/ans[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */