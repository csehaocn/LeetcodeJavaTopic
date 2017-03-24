public class Solution {
    
    // with an array you have to go through the array every time, a set or even linked list is better?
    // Let's see the difference of running time
    public boolean mustloseAux(char[] ca){
        for(int i = 1; i < ca.length; ++i){
            if('+' == ca[i] && '+' == ca[i-1]){
                ca[i] = '-';
                ca[i-1] = '-';
                if(false == canWinAux(ca)){
                    ca[i] = '+';
                    ca[i-1] = '+';
                    return false;
                }
                ca[i] = '+';
                ca[i-1] = '+';
            }
        }
        return true;
    }
    
    public boolean canWinAux(char[] ca){
        // Error: for(int i = 1; i != ca.length; ++i){
        for(int i = 1; i < ca.length; ++i){
            if('+' == ca[i] && '+' == ca[i-1]){
                ca[i] = '-';
                ca[i-1] = '-';
                if(mustloseAux(ca)){
                    // Error: reset + in this condition matters?
                    // isn't when must lose returns true, we can always win?
                    // OK. when canWinAux returns true, it is not the end of the program, mustLoseAux will keep searching.
                    ca[i] = '+';
                    ca[i-1] = '+';
                    return true;
                }
                ca[i] = '+';
                ca[i-1] = '+';
            }
        }
        
        return false;
    }
    
    public boolean canWin(String s) {
        char[] ca = s.toCharArray();
        return canWinAux(ca);
    }
}
