class Solution {
public:
int longestValidParentheses(string s) {  
    
    int res = 0;
    
    int len = s.size();
    
    if(0 == len)
        return 0;
        
    stack<int> sta;
    
    for(int i = 0; i != len; i++){
        
        char c = s[i];
        if('(' == c){
            sta.push(i);
        }
        else if(')'==c)
        {
            if(sta.empty()){
                sta.push(i);
            }
            else
            {
                int r_index = sta.top();
                if('(' == s[r_index]){
                    sta.pop();
                    if(sta.empty())
                    {
                        res = max(res, i+1);
                    }
                    else{
                        int l_index = sta.top();
                        res = max(res, i - l_index);
                    }
                }
                else
                {
                    sta.push(i);
                }
            }
        }
        
    }
    
    return res;
    
}  

};

Solution S{

    int longestValidParentheses(string s) {  
        const char* str = s.c_str();  
        int nMax=0;  
        const char *p = str;  
        vector<const char*> sta;  
        while(*p !='\0')  
        {  
            if(*p == '(')  
            {  
                sta.push_back(p);                      
            }  
            else  
            {  
                if(!sta.empty() && *sta.back()=='(')  
                {  
                    sta.pop_back();  
                    nMax = max(nMax, p-(sta.empty()?str-1:sta.back()));  
                }  
                else  
                {  
                    sta.push_back(p);  
                }  
            }  
            p++;  
        }  
        return nMax;  
    }

};
