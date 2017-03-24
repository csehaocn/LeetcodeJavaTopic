public class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> res = new ArrayList<>();
        int len = s.length();
        if(0 == len)
            return res;
        
        char[] cArr = s.toCharArray();
        
        for(int i = 1; i != len; ++i){
            if('+' == cArr[i] && '+' == cArr[i-1]){
                cArr[i-1] = '-';
                cArr[i] = '-';
                res.add(new String(cArr));
                cArr[i-1] = '+';
                cArr[i] = '+';
            }
        }
        
        return res;
    }
}
