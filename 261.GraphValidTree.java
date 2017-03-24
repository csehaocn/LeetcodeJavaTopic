public class Solution {
    
    // DFS, Dijkstra
    // UNION FIND
    class Node{
        
        int val;
        int color;
        ArrayList<Integer> children;
        
        public Node(int val){
            this.val = val;
            this.color = 0;
            children = new ArrayList<Integer>();
        }
        
        public void addChild(int val){
            children.add(val);
            return;
        }
  
    }
    
    public boolean DFS(Node[] nList, int index, int[] count){
        //System.out.println(index);
        Node n = nList[index];
        if(0 == n.color){
            n.color = 1;
            for(int i : n.children){
                boolean r = DFS(nList, i, count);
                if(!r)
                    return false;
            }
            n.color = 2;
            count[0]++;
            return true;
        }else if(2 == n.color){
            return false;
        }else{
            return true;
        }
        
    }
    
    public boolean validTree(int n, int[][] edges) {
        int len = edges.length;
        
        // Error: mis judgement.
        if(n < 2)
            return true;
        
        // Error: wrong judgement, if 0 == len.
        if(n-1 != len)
            return false;
            
        Node[] nList = new Node[n];
        
        for(int i = 0; i != n; ++i){
            nList[i] = new Node(i);
        }    
            
        for(int i = 0; i != len; ++i){
            int l = edges[i][0];
            int r = edges[i][1];
            /* Error: null pointer exception, edges might not cover all nodes.
            if(null == nList[l]){
                nList[l] = new Node(l);
                // Error: Null pointer exception, didn't add r.

            }
            if(null == nList[r]){
                // Error: Null pointer exception, didn't add r.
                nList[r] = new Node(r);
            }
            */
            
            nList[l].addChild(r);
            // Error: for dijkstra algorithm, it should be a undirected graph.
            nList[r].addChild(l);
        }
        
        int[] count = new int[1];

        if(DFS(nList, 0, count) && count[0] == n){
            return true;
        }else{
            return false;
        }

    }
}
