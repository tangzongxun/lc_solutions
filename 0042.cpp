class Solution {
public:
    int trap(vector<int>& height) {
        int rain_amount = 0;
        auto left_p = height.begin();
        auto right_p = height.end() - 1;
        int left_max = *left_p, right_max = *right_p;
        while (left_p < right_p) {
            if (left_max > right_max) {
                rain_amount += right_max - *right_p;
                right_p--;
                if (*right_p > right_max) {
                    right_max = *right_p;
                }
            } else {
                rain_amount += left_max - *left_p;
                left_p++;
                if (*left_p > left_max) {
                    left_max = *left_p;
                }
            }
        }
        return rain_amount;
    }
};
