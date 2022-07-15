class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size()-1;
        int maxv = 0;
        
        int p1mh = height[p1], p2mh = height[p2];
        while(p1 < p2){
            maxv = max(maxv, (p2-p1) * min(p1mh, p2mh));
            if(p1mh >= p2mh){
                p2--;
                p2mh = max(height[p2], p2mh);
            } else{
                p1++;
                p1mh = max(height[p1], p1mh);
            }
        }
        return maxv;
    }
};
