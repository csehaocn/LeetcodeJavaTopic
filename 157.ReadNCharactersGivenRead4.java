/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        
        char[] buf4 = new char[4];
        int i = read4(buf4);
        int ret = 0;
        while(ret < n){
            for(int k = 0; k < i && ret + k < n; ++k){
                buf[ret+k] = buf4[k];
            }
            ret += i;
            if(i < 4)
                break;
            i = read4(buf4);
        }
        
        return Math.min(ret, n);
        
    }
}
