class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t mv_cnt = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
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
