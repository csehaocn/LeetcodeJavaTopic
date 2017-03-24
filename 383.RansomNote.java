public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int lenR = ransomNote.length();
        int lenM = magazine.length();
        
        int[] cArray = new int[26];
        
        for(int j = 0; j != lenM; ++j){
            cArray[magazine.charAt(j) - 'a']++;
        }
        
        for(int i = 0; i != lenR; ++i){
            int index = ransomNote.charAt(i) - 'a';
            if(--cArray[index] < 0)
                return false;
        }
        
        
        
        return true;
    }
}
