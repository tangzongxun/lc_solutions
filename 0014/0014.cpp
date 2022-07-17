class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.empty()) {
            return result;
        }
        for (int i = 0; ; i++) {
            for (auto &str : strs) {
                if (str.size() <= i) {
                    return result;
                }
            }
            char c = strs[0][i];
            for (auto &str : strs) {
                if (str[i] != c) {
                    return result;
                }
            }
            result += c;
        }
    }
};
