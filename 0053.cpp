class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_value = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int current_max;
            if (max_so_far < 0) {
                max_so_far = nums[i];
            } else {
                max_so_far = max_so_far + nums[i];
            }
            if (max_so_far > max_value) {
                max_value = max_so_far;
            }
        }
        return max_value;
    }
};
