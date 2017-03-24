public class ZigzagIterator {
    
    Deque<Iterator<Integer> > dq;

    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        dq = new LinkedList<>();
        if(v1.iterator().hasNext())
            dq.addLast(v1.iterator());
        if(v2.iterator().hasNext())
            dq.addLast(v2.iterator());
    }

    public int next() {
        Iterator<Integer> it = dq.pollFirst();
        int ret = it.next();
        if(it.hasNext())
            dq.addLast(it);
        return ret;
    }

    public boolean hasNext() {
        if(dq.isEmpty())
            return false;
        else
            return true;
    }
}

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
