class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int len = nums.size();
        int cur_prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = cur_prefix;
            cur_prefix *= nums[i];
        }
        int cur_postfix = 1;
        for (int i = 0; i < nums.size(); i++) {
            auto pos = len - i - 1;
            ans[pos] = ans[pos] * cur_postfix;
            cur_postfix *= nums[pos];
        }
        return ans;
    }
};
