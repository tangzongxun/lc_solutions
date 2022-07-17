class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        for (size_t i = 0; i <= haystack.size() - needle.size(); i++) {
            bool matched = false;
            size_t j;
            for (j = 0; j < needle.size(); j++) {
                if (haystack[i + j] == needle[j]) {
                    continue;
                } else {
                    break;
                }
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};
