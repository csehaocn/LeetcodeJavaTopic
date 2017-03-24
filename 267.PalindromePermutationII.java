public class Solution {
    
    public boolean DFS(Map<Character, Integer> cMap, List<String> res, StringBuilder builder, int len, Character center){
        
        // Error: input "a" when we adopt s.length()/2 as the len
        //  if(builder.length() == len){
        //System.out.println("builder.length() = " + builder.length() + " len = " + len);
        if( (builder.length()*2 + (null == center?0:1)) == len){
            //System.out.println(len);
            //System.out.println("center = " + center);
            String rs = builder.reverse().toString();
            builder.reverse();
            res.add(builder.toString() + (null == center?"":center.toString()) + rs);
            //System.out.println("res.size() = " + res.size());
            return true;
        }
        
        for( char c : cMap.keySet() ){
            
            /*
            if( 1 == cMap.get(c) % 2){
                if(null != center){
                        return false;
                }
                center = c;
                cMap.put(c, cMap.get(c) -1); 
                // Error: when center was set as the last step, there is no DFS step anymore.
                // But set up a DFS here, result in a double result generated....
                // Double functioned DFS, can not easily maintain loop invariant....
                // Have to be careful.
                DFS(cMap, res, builder, len, center);
            }else{
            */
                if( cMap.get(c) > 0 ){
                /* When count were put to 0... i 0 != count is not working any more
                if( 1 == count % 2 ){
                    if(null != center){
                        return false;
                    }
                    center = c;
                    cMap.put(c, count -1);
                }
                */
                    
                builder.append(c);
                cMap.put(c, cMap.get(c)-2);
                DFS(cMap, res, builder, len, center);
                cMap.put(c, cMap.get(c)+2);
                builder.deleteCharAt(builder.length()-1);
                }
            
            // Error: here we used a count, even cMap.get(c) were altered, count were not...
            
        }
        
        return true;
        
    }
    
    public List<String> generatePalindromes(String s) {
        int len = s.length();
        List<String> res = new ArrayList<String>();
        
        if(0 == len) return res;
        
        Map<Character, Integer> cMap = new HashMap<>();
        
        for(int i = 0; i != len; ++i){
            char c = s.charAt(i);
            if(!cMap.containsKey(c)){
                cMap.put(c, 0);
            }
            cMap.put(c, cMap.get(c)+1);
        }
        
        StringBuilder builder = new StringBuilder();
        
        Character center = null;
        
        for( char c : cMap.keySet() ){
            
            if( 1 == cMap.get(c) % 2){
                if(null != center){
                        return res;
                }
                center = c;
                cMap.put(c, cMap.get(c) -1); 
                
            }
        }
        
        ArrayList<Character> keyList = new ArrayList<>(cMap.keySet());
        boolean ret = DFS(cMap, res, builder, len, center);

        if(!ret){
            return new ArrayList<String>();
        }else{
            return res;
        }
    }
}
