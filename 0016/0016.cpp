class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        vector<int>::iterator a_ptr, b_ptr;
        for (auto i = nums.begin(); i < nums.end(); i++) {
            a_ptr = i + 1;
            b_ptr = nums.end() - 1;
            while (a_ptr < b_ptr) {
                int sum = *i + *a_ptr + *b_ptr;
                if (sum < target) {
                    a_ptr++;
                } else {
                    b_ptr--;
                }
                if (abs(sum - target) < abs(ret - target)) {
                    ret = sum;
                }
            }
        }
        return ret;
    }
};
