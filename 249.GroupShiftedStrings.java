public class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        
        int len = strings.length;
        
        List<List<String>> ret = new ArrayList<>();
        
        Map<String, List<String>> slMap = new HashMap<>();
        
        if(0 == len)
            return ret;
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i != len; ++i){
            
            String s = strings[i];
            
            for(int j = 1; j != s.length(); ++j){
                // Error: Java can produce negative mod results. The difference is modulus and reminder.
                // http://stackoverflow.com/questions/5385024/mod-in-java-produces-negative-numbers
                int t = (s.charAt(j) - s.charAt(j-1))%26;
                t = t < 0? t + 26: t;
                sb.append( t + " " );
            }
            
            String si = sb.toString();
            
            //System.out.println("String = " + s + " Key = " + si);
            
            if(!slMap.containsKey(si)){
                slMap.put(si, new ArrayList<String>());
            }
            
            slMap.get(si).add(s);
            
            //Error: forgot to reset stringbuilder.
            sb.setLength(0);
            
        }
        
        for(String si : slMap.keySet()){
            ret.add(slMap.get(si));
        }
        
        return ret;
        
    }
}
