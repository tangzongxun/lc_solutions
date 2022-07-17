/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        size_t ptr = 0;
        
        sort(begin(intervals), end(intervals), [](const Interval& a, const Interval& b){
            if(a.start < b.start){
                return true;
            } else{
                return false;
            }
        });
        
        while(ptr + 1 < intervals.size()){
            if(intervals[ptr].end >= intervals[ptr+1].start){
                intervals[ptr].end = max(intervals[ptr].end, intervals[ptr+1].end);
                intervals.erase(begin(intervals) + ptr + 1);
            } else{
                ptr++;   
            }
        }
        
        return intervals;
        
    }
};
