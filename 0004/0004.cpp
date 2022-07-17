class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *array1 = &nums1, *array2 = &nums2;
        if (array1->size() > array2->size()) {
            swap(array1, array2);
        }
        // important: init left position from virtual element at array1[-1]
        long l_pos = -1, r_pos = array1->size() - 1;
        long half = (array1->size() + array2->size()) / 2;
        long total_size = array1->size() + array2->size();
        
        while(l_pos <= r_pos) {
            long ai = (l_pos + r_pos) / 2;
            long bi = half - ai - 2;
            
            int al, ar, bl, br;
            
            al = ai >= 0 ?
                    (*array1)[ai]
                    : numeric_limits<int>::min();
            ar = ai + 1 < array1->size() ?
                    (*array1)[ai + 1]
                    : numeric_limits<int>::max();
            bl = bi >= 0 ?
                    (*array2)[bi]
                    : numeric_limits<int>::min();
            br = bi + 1 < array2->size() ?
                    (*array2)[bi + 1]
                    : numeric_limits<int>::max();
            
            if (al <= br && bl <= ar) {
                return total_size % 2 == 0 ?
                        (min(ar, br) + max(al, bl)) / 2.0
                        : min(ar, br);
            } else if (al > br) {
                r_pos = ai - 1;
            } else {
                l_pos = ai + 1;
            }
        }
        throw runtime_error{"not found"};
    }
};
