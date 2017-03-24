public class SnakeGame {

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    class Pos{
        
        int x;
        int y;
        
        Pos(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        public int hashCode(){
            return x * 17 + y;
        }
        
        // Error!!!! : Wrong type of equals used, not overrided at all!!!
        public boolean equals(Object o){
            if(!(o instanceof Pos))
                return false;
            Pos p = (Pos)o;
            return p.x == x && p.y == y;
        }
    }
        
    Deque<Pos> q;
    Set<Pos> s;
    int fIndex;
    int m;
    int n;
    int[][] food;
    
    int score;
    
    public SnakeGame(int width, int height, int[][] food) {
        q = new LinkedList<Pos>();
        s = new HashSet<Pos>();
        
        fIndex = 0;
        Pos p = new Pos(0, 0);
        q.addLast(p);
        s.add(p);
        
        this.n = width;
        this.m = height;
        this.food = food;
        this.score = 0;
        
        validateFood();
    }
    
    public boolean validateFood(){
        while(fIndex < food.length){
                // Error: fIndex ++ then get the position. it is totally wrong.
                // fIndex++;
                Pos newFood = new Pos(food[fIndex][0], food[fIndex][1]);
                if(!s.contains(newFood)){
                    break;
                }
        }
        
        return fIndex < food.length;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    public int move(String direction) {
        Pos head = q.peekFirst();
        int i = head.x;
        int j = head.y;
        if(direction.equals("R")){
            // Error: i, j were used in reversed way 
            // i++;
            j++;
        }else if(direction.equals("D")){
            i++;
        }else if(direction.equals("U")){
            i--;
        }else if(direction.equals("L")){
            j--;
        }else{
            return -1;
        }
        
        // Hit bound
        if( i < 0 || i >= m || j < 0 || j >= n){
            //System.out.println("m =  " + m + " " + n);
            return -1;
        }
        
        Pos newHead = new Pos(i, j);

        //  Eat food ?
        // Error: out of bound, there is the case where there is no food anymore.
        if( fIndex < food.length && i == food[fIndex][0] && j == food[fIndex][1]){
            // Yes
            score++;
            fIndex++;
            // When I have this validate food function, timelimit is exceeded.
            // Obviously, I missunderstood the problem description.
            //validateFood();
        }else{
            Pos e = q.removeLast();
            s.remove(e);
        }
        
        // Hit itself
        // Error:
        // Be aware, the add new had and remove tail should be an atomic operation.
        // We add head, then judge, which result in a longer snake, temporarily.
        // Only when you eat food, you can be a longer snake
        // Therefore, validate new head should happen after remove the tail when no food.
        if(s.contains(newHead)){
            //System.out.println("Colide!");
            return -1;
        }
        
        // Valid new head pos,
        q.addFirst(newHead);
        s.add(newHead);
        
        return score;
    } 
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
