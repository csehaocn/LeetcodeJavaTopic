public class TwoSum {

    // Add the number to an internal data structure.
    Map<Integer, Integer> vcMap;
    // A faster solution, with a list to keep all the candidates.
    List<Integer> candidates;
    
    public TwoSum(){
        
        vcMap = new HashMap<>();
        candidates = new ArrayList<>();
    }
	public void add(int number) {
	    if(vcMap.containsKey(number)){
	        vcMap.put(number, vcMap.get(number)+1);
	    }else{
	        candidates.add(number);
	        vcMap.put(number, 1);
	    }
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	public boolean find(int value) {
	    for(int i : candidates){
	        int j = value - i;
	        if(i == j){
	            if(vcMap.get(j) >= 2) return true;
	        }else{
	            if(vcMap.containsKey(j)) return true;
	        }
	    }
	    
	    return false;
	}
	
	/*Time limite Exceeded:
    We don't need treemap actually
    class IntegerObj implements Comparable<IntegerObj>{
        int x;
        public IntegerObj(int x){
            this.x = x;
        }
        public int compareTo(IntegerObj z){
            if(this.x <= z.x)
                return -1;
            else
                return 1;
        }
    }

    TreeSet<IntegerObj> ts;
    
    public TwoSum(){
        ts = new TreeSet<>();
    }
    // Add the number to an internal data structure.
	public void add(int number) {
	    IntegerObj i = new IntegerObj(number);
	    //System.out.println();
	    ts.add(new IntegerObj(number));
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	public boolean find(int value) {
	    Iterator<IntegerObj> it = ts.iterator();
	    Iterator<IntegerObj> rit = ts.descendingIterator();
	    if(!it.hasNext()) return false;
	    if(!rit.hasNext()) return false;
	    IntegerObj i = it.next();
	    IntegerObj j = rit.next();
	    //System.out.println(i);
	    //System.out.println(j);
	    // Compare between Integer is tricky...
	    // http://stackoverflow.com/questions/1514910/how-to-properly-compare-two-integers-in-java ...
	    // ts.add(new Integer()); would not solve the problem?
	    // OK, the set does not allow duplications.........................
	    // TreeSet use comapre instead of hashCode and equals........
	    while(i != j){
	        int sum = i.x + j.x;
	        if(sum == value){
	            return true;
	        }else{
	            if(i.x == j.x)
	                return false;
	            if(sum < value){
	                if(!it.hasNext()) return false;     
	                i = it.next();
	            }else{
	                if(!rit.hasNext()) return false;
	                j = rit.next();
	            }
	        }
	        // Error: Here i and j are different alreay
	        //if(i.x == j.x)
	        //    return false;
	    }
	    
	    return false;
	}
	*/
}


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum = new TwoSum();
// twoSum.add(number);
// twoSum.find(value);
