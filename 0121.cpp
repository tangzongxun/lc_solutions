class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max_profit = 0;
        for(int p : prices){
            if(p < min){
                min = p;
            }
            if(p - min > max_profit){
                max_profit = p - min;
            }
        }
        return max_profit;
    }
};
