class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx[256];
        for(int i = 0; i < 256; i++){
            idx[i] = -1;
        }
        
        int max = 0;
        int start = 0;
        
        for(int i = 0; i < s.size(); i++){
            unsigned char c = (unsigned char)s[i];
            if(idx[c] < start){
                if(max < i - start + 1){
                    max = i - start + 1;
                }
            } else{
                start = idx[c] + 1;
            }
            idx[c] = i;
        }
        
        return max;
    }
};
