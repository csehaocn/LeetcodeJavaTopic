public class RandomizedSet {



/*  Error: Major Error, the correct move for del is to move the last element to replace the deleting element. 

        Using direct del with count-- result holes in indexing range.

    

    Map<Integer, Integer> ivMap;

    Map<Integer, Integer> viMap;

    int count;

    

    public RandomizedSet() {

        // Can be done through dual hash maps, index to value, value to index hash map

        // Arraylist can be used in replace for the index to value map.

        // Actually no, the remove operation requires O(1) complexity as well

        ivMap = new HashMap<Integer, Integer>();

        viMap = new HashMap<Integer, Integer>();

        count = 0;

    }

    

    public boolean insert(int val) {

        if(viMap.containsKey(val)){

            return false;

        }else{

            ++count;

            ivMap.put(count, val);

            viMap.put(val, count);

            return true;

        }

    }

    

    public boolean remove(int val) {

        if(viMap.containsKey(val)){

            // Error: OK, yes, count-- is correct, but the used index should not be used anymore.

            // Yes, the correct way should be move the last index to current index.

            ivMap.remove(viMap.get(val));

            viMap.remove(val);

            count--;

            return true;

        }else{

            return false;

        }

    }

    

    public int getRandom() {

        // Math.random() [0.0, 1.0)

        // Error: Null Pointer return ivMap.get((int)(Math.random() * count)+1);

        return ivMap.get((int)(Math.random() * count)+1);

    }

    

    */

    private ArrayList<Integer> ivList = new ArrayList<Integer>();

    private Map<Integer, Integer> viMap = new HashMap<Integer, Integer>();

    /** Initialize your data structure here. */

    public RandomizedSet() {

        ivList = new ArrayList<Integer>();

        viMap = new HashMap<Integer, Integer>();

    }

    

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */

    public boolean insert(int val) {

        if(viMap.containsKey(val)){

            return false;

        }else{

            ivList.add(val);

            viMap.put(val, ivList.size()-1);

            return true;

        }

    }

    

    /** Removes a value from the set. Returns true if the set contained the specified element. */

    public boolean remove(int val) {

        if(viMap.containsKey(val)){

            // Error: Line 72: java.lang.IndexOutOfBoundsException: Index: 0, Size: 0

            // For this statement, remove operates first, them set does not work anymore......

            // Reduce three statement into one result in error.....

            // ivList.set(viMap.get(val), ivList.remove(ivList.size()-1));

            // Actually, it should be different case for deleting the end of element or not

            int index = viMap.get(val);

            if(ivList.size()-1 == index){

                ivList.remove(ivList.size()-1);

                viMap.remove(val);

            }else{

                // Error: the four operations better go with temperal storages, operations on data structures change the return value of operations from time to time. 

                int endVal = ivList.get(ivList.size()-1);

                int valIndex = viMap.get(val);

                ivList.remove(ivList.size()-1);

                ivList.set(valIndex, endVal);

                viMap.remove(val);

                viMap.put(endVal, valIndex);

            }

            return true;

        }else{

            return false;

        }

    }

    

    /** Get a random element from the set. */

    public int getRandom() {

        int index = (int)(Math.random()*ivList.size());

        return ivList.get(index);

    }

}



/**

 * Your RandomizedSet object will be instantiated and called as such:

 * RandomizedSet obj = new RandomizedSet();

 * boolean param_1 = obj.insert(val);

 * boolean param_2 = obj.remove(val);

 * int param_3 = obj.getRandom();

 */
