public class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int len = words.length;
        if(0 == len)
            return 0;
        
        int ret = len;
        
        if(word1.equals(word2)){
            int index = -1;
            for(int i = 0; i != len; ++i){
                String s = words[i];
                if(s.equals(word1)){
                    if(-1 != index){
                            ret = Math.min(ret, i-index);
                    }
                    index = i;
                }
            }
            
            return ret;
        }else{
            int m = -1;
            int n = -1;
            for(int i = 0; i != len; ++i){
                String s = words[i];
                if(s.equals(word1)){
                    m = i;
                }
                
                // A solution with shorter code:
                // we can put if(word1.equals(word2)) here with ret = Math.min();
                // But it might run slower
                
                if(s.equals(word2)){
                    n = i;
                }
                
                if(-1 != m && -1 != n){
                    ret = Math.min(ret, Math.abs(m-n));
                }
            }
            
            return ret;
        }
    }
}
