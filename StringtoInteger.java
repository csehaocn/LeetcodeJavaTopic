public class Solution {
    public int myAtoi(String str) {
        int len = str.length();
        int res = 0;
        boolean pn = true;
        boolean hasValue = false;
        boolean pnvalid = false;
        
        int md10 = Integer.MAX_VALUE/10;
        int md10tail = Integer.MAX_VALUE - md10;
        // It is necessary to Integer.MIN_VALUE as well. Omitted here.

        for(int i = 0; i < len; ++i){
            Character c = str.charAt(i);
            if('+' == c){
                if(pnvalid == true)
                    return 0;
                pn = true;
                pnvalid = true;
            }else if('-' == c){
                if(pnvalid == true)
                    return 0;
                pn = false;
                pnvalid = true;
            }else if(Character.isDigit(c)){
                
                if(res > md10){
                    return pn?Integer.MAX_VALUE:Integer.MIN_VALUE;    
                }
                res*= 10;
                int value = (int)(Character.getNumericValue(c));
                if(Integer.MAX_VALUE - value < res)
                    return pn?Integer.MAX_VALUE:Integer.MIN_VALUE;
                res+= value;
                hasValue = true;
            }else if(c == ' '){
                if(false == hasValue && pnvalid == false)
                    continue;
                    
                if(hasValue || pnvalid == true){
                    return pn?res:-1*res; 
                }
                
            }else{
                if(hasValue){
                    return pn?res:-1*res;
                }
                else{
                    return 0;
                }
            }
        }
        
        return pn?res:-1*res;
        
    }
}
