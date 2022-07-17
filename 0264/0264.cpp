
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_vec{1};
        int count = 1;
        
        size_t i2 = 0, i3 = 0, i5 = 0;
        while(count < n){
            int n1 = 2 * ugly_vec[i2];
            int n2 = 3 * ugly_vec[i3];
            int n3 = 5 * ugly_vec[i5];
            
            int num;
            
            if(n1 <= n2 && n1 <= n3){
                num = n1;
                i2++;
            }
            if(n2 <= n1 && n2 <= n3){
                num = n2;
                i3++;
            }
            if(n3 <= n2 && n3 <= n1){
                num = n3;
                i5++;
            }
            
            ugly_vec.push_back(num);
            count++;
            
            if(2 * ugly_vec[i2] == num){
                i2++;
            }
            if(3 * ugly_vec[i3] == num){
                i3++;
            }
            if(5 * ugly_vec[i5] == num){
                i5++;
            }
        }
        return ugly_vec[n-1];
    }
};
