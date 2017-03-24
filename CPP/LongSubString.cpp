// The trick here is '0' is not the smallest one. ' ' space is the smallest one

// The second problem is program won't crash with a negative index like countTable[-14];
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int length = s.size();
        if (length == 0) {
            return 0;
        }
        int countTable[256];
        for(int i = 0; i != 256; ++i)
            countTable[i] = -1;
        int m = 1;
        int start = 0;
        int end = 1;
        
        countTable[s[0]-' '] = 0;
        while (end < length) {
            //Has not reached a duplicate char
            if (countTable[s[end]-' '] >= start) {
                start = countTable[s[end]-' '] + 1;             
            }
            m = max(m, end - start + 1);
            countTable[s[end]-' '] = end;
            end++;
        }
        return m;
    }
};
