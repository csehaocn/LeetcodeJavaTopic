public class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int len = words.length;
        int lastIndex1 = -1;
        int lastIndex2 = -1;
        int ret = -1;
        
        if(0 == len)
            return 0;
        
        for(int i = 0; i != len; ++i){
            String s = words[i];
            if(s.equals(word1)){
                lastIndex1 = i;
                if(lastIndex2 == -1){
                    continue;
                }else{
                    if(-1 == ret){
                        ret = Math.abs(lastIndex1 - lastIndex2);
                    }else{
                        ret = Math.min(ret, Math.abs(lastIndex1 - lastIndex2));
                    }
                }
            }
            
            if(s.equals(word2)){
                lastIndex2 = i;
                if(lastIndex1 == -1){
                    continue;
                }else{
                    if(-1 == ret){
                        ret = Math.abs(lastIndex1 - lastIndex2);
                    }else{
                        ret = Math.min(ret, Math.abs(lastIndex1 - lastIndex2));
                    }
                }
            }
            
        }
        
        return ret;
    }
}
