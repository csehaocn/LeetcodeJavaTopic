/* The knows API is defined in the parent class Relation.
      boolean knows(int a, int b); */

public class Solution extends Relation {
    public int findCelebrity2(int n) {
        // array can be a better solution?
        // it can be but a little hard to program
        return 0;
    }
    
    public int findCelebrity(int n) {
        if(0 == n)
            return -1;
        Set<Integer> s = new HashSet<Integer>();
        Set<Integer> tmp = new HashSet<>();
        for(int i = 0; i != n; ++i){
            s.add(i);
        }
        Integer first = null;
        while(s.size() > 1){
            first = null;
            for(int i : s){
                if(null == first){
                    first = i;
                }else{
                    boolean ans = knows(first, i);
                    if(ans){
                        tmp.add(i);
                    }else{
                        tmp.add(first);
                    }
                    first = null;
                }
            }
            // Error: the last element in the set with odd elements is not added in the tmp set.
            if(null != first)
                tmp.add(first);
            s = tmp;
            tmp = new HashSet<>();
        }
        
        for(int c : s){
            for(int i = 0; i != n; ++i){
                if(i != c && (!knows(i, c) || knows(c, i))){
                    return -1;
                }
            }
            return c;
        }
        
        return -1;
    }
}
