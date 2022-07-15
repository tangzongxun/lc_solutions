class Solution {
private:
    int findPivot(vector<int>& nums, int start, int end){
        if(start > end){
            return nums.size();
        }
        
        int mid = (start + end) / 2;
        if(mid == 0){
            if(end == 1 && nums[end] < nums[start]){
                return 1;
            }
            return nums.size();
        }
        if(nums[mid] < nums[mid-1]){
            return mid;
        }
        
        if(nums[mid] > nums[0]){
            return findPivot(nums, mid + 1, end);
        }
        
        return findPivot(nums, start, mid - 1);       
    }
    
    int binsearch(vector<int>& nums, int target, int start, int end){
        if(start > end){
            return -1;
        }
        
        int mid = (start + end) / 2;
        if(nums[mid] == target){
            return mid;
        }
        
        if(target > nums[mid]){
            return binsearch(nums, target, mid + 1, end);
        }
        
        return binsearch(nums, target, start, mid - 1);
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()){
            return -1;
        }
        
        int pivot = findPivot(nums, 0, nums.size()-1);
        cerr << pivot << endl;
        if(target >= nums[0]){
            return binsearch(nums, target, 0, pivot-1);
        }
        return binsearch(nums, target, pivot, nums.size()-1);
    }
    

};
