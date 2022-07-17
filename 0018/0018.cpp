
template<typename T>
typename std::vector<T>::iterator next_unique(
        typename std::vector<T>::iterator iter,
        typename std::vector<T>::iterator end) {
    auto next = iter + 1;
    while (next < end && *next == *iter) {
        next = next + 1;
    }
    return next;
}

template<typename T>
typename std::vector<T>::iterator previous_unique(
        typename std::vector<T>::iterator iter,
        typename std::vector<T>::iterator begin) {
    auto next = iter - 1;
    while (next > begin && *next == *iter) {
        next = next - 1;
    }
    return next;
}

std::vector<pair<int, int>> twoSumSorted(
        vector<int>::iterator start, vector<int>::iterator end, int target) {
    std::vector<pair<int, int>> result;
    auto left = start;
    auto right = end;
    while (left < right) {
        auto sum = *left + *right;
        if (sum == target) {
            result.push_back(make_pair(*left, *right));
            left = next_unique<int>(left, end);
            continue;
        }
        if (sum < target) {
            left = next_unique<int>(left, end);
            continue;
        }
        if (sum > target) {
            right = previous_unique<int>(right, start);
            continue;
        }
    }
    return result;
}

vector<vector<int>> threeSum(
        vector<int>::iterator start, vector<int>::iterator end, int target) {
    vector<vector<int>> result;
    for (auto i = start; i < end - 2; i = next_unique<int>(i, end)) {
        auto sub_result = twoSumSorted(i + 1, end - 1, target - (*i));
        for (auto pair : sub_result) {
            result.push_back(std::vector<int>{*i, pair.first, pair.second});
        }
    }
    return result;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return vector<vector<int>>{};
        }
        vector<vector<int>> result;
        for (auto i = nums.begin(); i < nums.end() - 3; i = next_unique<int>(i, nums.end())) {
            auto sub_result = threeSum(i + 1, nums.end(), target - (*i));
            for (auto vec : sub_result) {
                vector<int> ans{*i};
                for (auto n : vec) ans.push_back(n);
                result.push_back(ans);
            }
        }
        return result;
    }
};
