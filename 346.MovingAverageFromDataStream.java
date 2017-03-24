public class MovingAverage {

    /** Initialize your data structure here. */
    int sum;
    int size;
    Deque<Integer> dq;
    
    public MovingAverage(int size) {
        sum = 0;
        this.size = size;
        dq = new LinkedList<Integer>();
        
    }
    
    public double next(int val) {
        if(dq.size() < size){
            dq.addLast(val);
            sum += val;
        }else{
            sum -= dq.pollFirst();
            dq.addLast(val);
            sum += val;
        }
        
        return (double)sum/(double)dq.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
