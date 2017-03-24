public class Solution {
    
    public void DFS(char[] c, int index, StringBuilder builder, boolean isDigit, List<String> res){
        if(index == c.length){
            res.add(builder.toString());
            return;
        }
        
        if(!isDigit){
            for(int i = index; i < c.length; ++i){
                String s = (i-index+1)+"";
                builder.append(s);
                DFS(c, i+1, builder, true, res);
                builder.delete(builder.length()-s.length(), builder.length());
            }
        }
        
        builder.append(c[index]);
        DFS(c, index+1, builder, false, res);
        builder.deleteCharAt(builder.length()-1);
        return;
    }
    
    public List<String> generateAbbreviations(String word) {
        char[] c= word.toCharArray();
        StringBuilder builder = new StringBuilder();
        
        List<String> res = new ArrayList<>();
        DFS(c, 0, builder, false, res);
        
        return res;
    }
}
