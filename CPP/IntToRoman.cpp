class Solution {
public:
    string intToRoman(int num) {
        
        vector<char> rc = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    
        int range = 1000;
    
        int index = 6;
    
        string res;
    
        while(num){
        
        int digit = num / range;
            
            if(0 < digit && digit <=3)
            {
                while(digit){
                    res.push_back(rc[index]);
                    --digit;
                }
            }
            else if(4 == digit)
            {
                res.push_back(rc[index]);
                res.push_back(rc[index+1]);
            }
            else if( 4 < digit && digit <= 8)
            {
                res.push_back(rc[index+1]);
                digit -= 5;
                while(digit){
                    res.push_back(rc[index]);
                    --digit;
                }
                
            }
            else if( 9 == digit){
                res.push_back(rc[index]);
                res.push_back(rc[index+2]);
            }
            
        num = num % range;
        range /= 10;
        index -= 2;
        }
    return res;
    }
};
