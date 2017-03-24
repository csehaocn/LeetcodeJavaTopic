public class HitCounter {
    
    class hitObj{
        
        int ts;
        int c;
        
        hitObj(int ts){
            this.ts = ts;
            c = 1;
        }
        
        public void inc(){
            c++;
        }
    }
    
    /** Initialize your data structure here. */
    int count;
    int lastHitTs;
    Deque<hitObj> dq;
    
    public HitCounter() {
        count = 0;
        lastHitTs = 0;
        dq = new LinkedList<hitObj>();
    }
    
    public void processDq(int timestamp){
        //System.out.println("Processing!");
        //System.out.println(dq.size());
        // Error: should be <= instead of < 
        while( !dq.isEmpty() && dq.peekFirst().ts <= timestamp - 300){
            //System.out.println("timestamp = " + timestamp + " ts = " + dq.peekFirst().ts);
            count -= dq.pollFirst().c;
        }
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    // It is even slower with a keep of lasthit ts.....
    public void hit(int timestamp) {
        if(lastHitTs == timestamp){
            dq.peekLast().inc();
        }else{
            processDq(timestamp);
            dq.addLast(new hitObj(timestamp));
            lastHitTs = timestamp;
        }
        count++;
        return;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        processDq(timestamp);
        return count;
    }
    
    /*
    int ts;
    int count;
    // Error: Array method failed when [200] [1466000000001]
    // Turn to queue based method
    int[] cArr;
    
    public HitCounter() {
        ts = 0;
        count = 0;
        cArr = new int[300];
    }
    
    
    public void updateArray(int timestamp){
        while(timestamp > ts){
            ++ts;
            int tsMod = ts%300;
            count-= cArr[tsMod];
            cArr[tsMod] = 0;
        }
    }
        
    public void hit(int timestamp) {
        updateArray(timestamp);
        cArr[ts%300]++;
        count++;
    }
    
        // Error: forgot about update array is needed for getHits too!!!
    public int getHits(int timestamp) {
        updateArray(timestamp);
        return count;
    }
    */
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
