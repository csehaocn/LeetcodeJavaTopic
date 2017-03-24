public class Vector2D implements Iterator<Integer> {

    Integer current;
    Iterator<List<Integer>> fit;
    Iterator<Integer> sit;

    public Vector2D(List<List<Integer>> vec2d) {
        fit = vec2d.iterator();
        if(fit.hasNext()){
            sit = fit.next().iterator();
            // Error: next the while loop for case [[],[3]]
            // can be solved by call the next() function once and the start.
            //if(sit.hasNext()){
            //    current = sit.next();
            //}else{
            //    current = null;
            //}
            next();
        }else{
            current = null;
        }
    }

    @Override
    public Integer next() {
        Integer ret = current;
        if(sit.hasNext()){
            current = sit.next();
            return ret;
        }else{
            while(true){
                if(sit.hasNext()){
                    current = sit.next();
                    return ret;
                }else{
                    if(fit.hasNext()){
                        sit = fit.next().iterator();
                    }else{
                        current = null;
                        return ret;
                    }
                }
            }
        }
        
    }

    @Override
    public boolean hasNext() {
        if(null != current)
            return true;
        else
            return false;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i = new Vector2D(vec2d);
 * while (i.hasNext()) v[f()] = i.next();
 */
