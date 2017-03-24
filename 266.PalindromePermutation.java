public class Solution {
    public boolean canPermutePalindrome(String s) {
        // Error: OK, for random string, alphabet array would not work
        int len = s.length();
        if(0 == len)
            return true;
            
        Map<Character, Integer> ciMap = new HashMap<>();
        
        for(int i = 0; i != len; ++i){
            Character c = s.charAt(i);
            if(!ciMap.containsKey(c)){
                ciMap.put(c, 0);
            }
            ciMap.put(c, ciMap.get(c)+1);
        }
        
        boolean oneOdd = false;
        for(Character c: ciMap.keySet()){
            if(1 == ciMap.get(c)%2){
                if(false == oneOdd){
                    oneOdd = true;
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
}
