public class Solution {
    
    public void getFactorsAux(List<List<Integer>> res, List<Integer> path, int n, int factor){
        
        int u = (int)Math.sqrt(n);
        for(int i = factor; i <= u; ++i){
            if( 0 == n % i){
                int d = n / i;
                path.add(i);
                path.add(d);
                res.add(new ArrayList<Integer>(path));
                path.remove(path.size()-1);
                getFactorsAux(res, path, d, i);
                path.remove(path.size()-1);
            }
        }
        
        return;
    }
    
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        if(n <= 1)
            return res;
            
        getFactorsAux(res, path, n, 2);
        
        return res;
    }
    /*
    public void getFactorsAux(List<List<Integer>> res, List<Integer> path, int n, int factor){
        //System.out.println("n = " + n + "factor = " + factor);
        
        // Running Time we don't really need n == 1 as the end condition
        // it is a multi length path problem just like the android unlock pattern problem.
        if(n <= 1 && path.size() > 1){
            res.add(new ArrayList<Integer>(path));
            return ;
        }
        // Error: for(int i = factor; i < n; ++i){
        // Yes, n should be needed in later DFS calls, but not needed in the first call.
        for(int i = factor; i <= n; ++i){
            if(0 == n % i){
                path.add(i);
                //getFactorsAux(res, path, n/i, factor);
                getFactorsAux(res, path, n/i, i);
                path.remove(path.size()-1);
            }
        }
        
        return;
        
    }
    
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        if(n <= 1)
            return res;
            
        getFactorsAux(res, path, n, 2);
        
        return res;
    }
    */
}
