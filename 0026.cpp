class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t mv_cnt = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                mv_cnt++;
                continue;
            }
            if (mv_cnt > 0) {
                nums[i - mv_cnt] = nums[i];
            }
        }
        return nums.size() - mv_cnt;
    }
};
