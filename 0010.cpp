class Solution {
public:
    bool isMatch(string s, string p) {
        auto memo = vector<vector<int>>(s.size()+1, vector<int>(p.size()+1, -1));
        function<bool(string::iterator, string::iterator)> match;
        match = [&](string::iterator sp, string::iterator pp){
            if(memo[sp-s.begin()][pp-p.begin()] != -1){
                return (bool)(memo[sp-s.begin()][pp-p.begin()]);
            }
            if(sp == s.end() && pp == p.end()){
                memo[sp-s.begin()][pp-p.begin()] = 1;
                return true;
            }
            
            if(p.end() - pp > 1 && *(pp+1) == '*'){
                if(sp == s.end()){
                    return match(sp, pp + 2);
                }
                
                if(*sp == *pp || *pp == '.'){
                    return match(sp + 1, pp) || match(sp, pp + 2);
                }
                return match(sp, pp + 2);
            }
            if(pp != p.end() && sp != s.end()){
                if(*sp == *pp || *pp == '.'){
                    return match(sp + 1, pp + 1);
                }
            }
            memo[sp-s.begin()][pp-p.begin()] = 0;
            return false;
        };
         
        
        
        return match(s.begin(), p.begin());
    }
};
