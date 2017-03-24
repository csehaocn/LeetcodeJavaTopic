// It is accepted but we should seriiously consider about the situations.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution1{
    public:
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            cout << s << "    " << p << endl;

            int lenS = strlen(s); 

            // Caution the fault I made here,
            // Be very careful with the copys, yy, 
            // int lenP = strlen(s); 
            int lenP = strlen(p);

            cout << lenS << "    " << lenP << endl;

            if('\0' == *p) return '\0' == *s;  

            if( *(p+1)=='*' )
            {
                if('*' == *p)
                {
                    return false;
                }
                else if( 0 == *s )
                {
                   return isMatch(s, p+2); 
                }
                else if( '.' == *p || *s == *p)
                {
                    return isMatch(s+1,p) || isMatch(s, p+2); 
                }
                
                    return *p == *s && isMatch(s+1,p) || isMatch(s, p+2); 
                
            }
            else
            // *(p+1) != '*'
            {
                if('*'==*p) 
                {
                    return false;
                }
                else
                {
                    return ( ('.' == *p && *s != '\0') || *s == *p) && isMatch(s+1, p+1);
                    //return ('.' == *p || *s == *p) && isMatch(s+1, p+1);
                }
                
                return *s ==*p && isMatch(s+1, p+1);;
            }

        }
};


class Solution {
    
    vector<vector<int> > DP;
    
    const char *m_s;
    const char *m_p;
    
    bool isMatch_DP(int lenS, int lenP){
        //cout << lenS << lenP << endl;
        if(lenS < 0 || lenP < 0) return false;
        if(-1 != DP[lenS][lenP])
            return DP[lenS][lenP];
            
        // 3 cases of patterns
        
        if('*' == (m_p[lenP-1])){
            if(lenP <=1 )
                DP[lenS][lenP] = 0;
            else{
            // OMG, notice that the ? : operation has a lower priority than ||, ( ) is so neccessary!!! 
                DP[lenS][lenP] = isMatch_DP(lenS, lenP-2) || (lenP >= 2 && (m_p[lenP-2] == m_s[lenS-1] || m_p[lenP-2] == '.' )? isMatch_DP(lenS-1, lenP) : 0); 
            }
        } else if('.' == (m_p[lenP-1]) || m_s[lenS-1] == m_p[lenP-1]){
            DP[lenS][lenP] = isMatch_DP(lenS-1, lenP-1) ? 1 : 0;
        }
        else{
            DP[lenS][lenP] = 0;
        }

        cout << "lenS " << lenS << " lenP " << lenP << " DP " << DP[lenS][lenP] << endl;        
        return DP[lenS][lenP];
    }
    
public:
    bool isMatch(const char *s, const char *p) {
        int lenS = strlen(s);
        int lenP = strlen(p);
        DP = vector<vector<int> >(lenS+1, vector<int>(lenP+1, -1));
        for(int i = 0; i != lenS+1; ++i){
            DP[i][0] = 0;
        }

        DP[0][0] = 1;
        
        m_s = s;
        m_p = p;
        
        return isMatch_DP(lenS, lenP);
        
    }
};


int main(){
    Solution s;
//    if(s.isMatch("baccbbcbcacacbbc", "c*.*b*c*ba*b*b*.a*")) cout << "true"; else cout << "false";
//    if(s.isMatch("aa", ".*")) cout << "true"; else cout << "false";
//      if(s.isMatch("aaa", "ab*a")) cout << "true"; else cout << "false";
//      if(s.isMatch("aab", "c*a*b")) cout << "true"; else cout << "false";
//      if(s.isMatch("abcd", "d*")) cout << "true"; else cout << "false";
      if(s.isMatch("aa", ".*")) cout << "true"; else cout << "false";
}

