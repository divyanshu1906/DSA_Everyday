class Solution {
public:
    int findingPair(int low, int mid, int high, vector<int>&nums){
        int count = 0;

        int right = mid+1;

        for(int left=low; left<=mid; left++){
            while(right <= high && (nums[left] > (long long)nums[right]*2)) right++;
            count += (right-(mid+1));
        }

        return count;
    }
    void merge(int low, int mid, int high, vector<int>&nums){
        vector<int>temp;

        int left  = low;
        int right =  mid+1;

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }
    int mergeSort(int low, int high, vector<int>&nums){
        if(low >= high) return 0;

        int count = 0;
        
        int mid = low + (high - low) / 2;

        count += mergeSort(low, mid, nums);
        count += mergeSort(mid+1, high, nums);

        count += findingPair(low, mid, high, nums);

        merge(low, mid, high, nums);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};