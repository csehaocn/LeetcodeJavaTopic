#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:

        int KMP(string s, string p){

            int lenP = p.size(); 
            int lenS = s.size();

            if(0 == lenP || 0 == lenS)
                return -1;

            vector<int> pi(lenP);

            pi[0] = -1;

            for(int i = 1; i != pi.size(); ++i)
            {
                int pre_index = pi[i-1];
                while(1)
                {
                    if(p[i] == p[pre_index+1])
                    {
                        pi[i] = pre_index+1;
                        break;
                    }
                    else
                    {
                        if(-1 == pre_index)
                        {
                            pi[i] = -1;
                            break;
                        }
                        else
                            pre_index = pi[pre_index];
                    }
                }
            }

            int p_index = -1;
            int s_index = -1;

            while(p_index != lenP-1 && s_index != lenS-1 )
            {
                cout << s_index << " " << p_index << endl;
                if(p[p_index+1] == s[s_index+1])
                {
                    ++p_index;
                    ++s_index;
                }
                else if(p_index != -1){
                    p_index = pi[p_index];
                }
                else
                {
                    ++s_index;
                }
            }
            
            cout << s_index << " " << p_index << endl;
            if(lenP-1 == p_index)
            {
                return s_index - lenP +1; 
            }

            return -1;
        }

        char *strStr(char *haystack, char *needle) {
            string s(haystack);
            string p(needle);
            if(p.empty())
                return haystack;
            int index = KMP(s,p);
            if(-1 == index)
                return NULL;
            else{
                return haystack+index;
            }

        }
};

int main(){
    Solution S;
    char hay[] = "a";
    char needle[] = "a";
    char* c = S.strStr(hay, needle); 
    cout << string(c); 
}
