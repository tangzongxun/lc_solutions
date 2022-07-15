class Solution {
public:
    string longestPalindrome(string s) {
        string max;
        for(int i = 0; i < s.size(); i++){
            string tmp1 = subpalindrome(s, i, true);
            if(tmp1.size() > max.size()){
                max = tmp1;
            }
            string tmp2 = subpalindrome(s, i, false);
            if(tmp2.size() > max.size()){
                max = tmp2;
            }
        }
        return max;
    }
    
    string subpalindrome(string& s, size_t center, bool even){
        size_t start, end;
        if(even){
            start = center + 1;
            end = center;
            if (s[start] != s[end]){
                return string{};
            }
        } else{
            start = center;
            end = center;
        }
        while(start > 0 && end < s.size() - 1){
            if(s[start-1] == s[end + 1]){
                start--;
                end++;
            } else{
                break;
            }
        }
        return s.substr(start, end - start + 1);
    }
    
};


