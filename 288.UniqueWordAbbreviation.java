public class ValidWordAbbr {

    Map<String, Set<String>> abMap;
    
    public String toKey(String s){
        if(s.length() <= 2){
                return s;
            }else{
                return "" + s.charAt(0) + (s.length() - 2) + s.charAt(s.length()-1);
        }
    }
    
    public ValidWordAbbr(String[] dictionary) {
        abMap = new HashMap<>();
        for(int i = 0; i != dictionary.length; ++i){
            String s = dictionary[i];
            String ab = toKey(s);
            if(!abMap.containsKey(ab)){
                abMap.put(ab, new HashSet<String>());
            }
            abMap.get(ab).add(s);
        }
    }

    public boolean isUnique(String word) {
        String ab = toKey(word);
        return !abMap.containsKey(ab) || (1 == abMap.get(ab).size() && abMap.get(ab).contains(word));
    }
}


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa = new ValidWordAbbr(dictionary);
// vwa.isUnique("Word");
// vwa.isUnique("anotherWord");
