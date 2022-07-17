class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        target_char_dict = dict()
        for s in s1:
            target_char_dict[s] = target_char_dict.get(s, 0) + 1
        distance = len(s1)
        
        # interval: [l, r)
        l, r = 0, 0
        window_char_dict = dict()
        while r < len(s2):
            # extend to right side
            to_be_added = s2[r]
            r += 1
            window_char_dict[to_be_added] = window_char_dict.get(to_be_added, 0) + 1
            # update distance
            if window_char_dict[to_be_added] <= target_char_dict.get(to_be_added, 0):
                distance -= 1
            else:
                distance += 1
            
            # shrink from left side
            if r - l > len(s1):
                to_be_dropped = s2[l]
                l += 1
                window_char_dict[to_be_dropped] = window_char_dict[to_be_dropped] - 1
                if window_char_dict[to_be_dropped] >= target_char_dict.get(to_be_dropped, 0):
                    distance -= 1
                else:
                    distance += 1
            if distance == 0:
                return True
        
        return False
