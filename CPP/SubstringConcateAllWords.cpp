#include<vector>
#include<string>
#include<map>
#include"util.hpp"

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {

        vector<int> res;
   
        map<string, int> m_MapOfString;


        int lenS = S.size();
        int sizeL = L.size(); 

        if(0 == sizeL)
            return res;

        int lenL = L[0].size();
    
        for(int i = 0; i != sizeL; ++i)   
        {
            if(m_MapOfString.find(L[i])==m_MapOfString.end())
            {
                m_MapOfString[L[i]] = 1;
            }
            else
            {
                m_MapOfString[L[i]] += 1;
            }
        }

        map<string, int> m_emptyMap = m_MapOfString;

        //pMap(m_MapOfString);

        for(int i = 0; i != lenL; ++i)
        {
            //cout << i << endl;
            
            int l = i;    

            int count = 0; 

            m_MapOfString = m_emptyMap;

            for(int j = i; j != lenS; j+=lenL)
            {
                if(l > lenS-lenL*sizeL)
                    break;

                string subS = S.substr(j,lenL); 
                if(m_MapOfString.find(subS) == m_MapOfString.end())
                {
                    count = 0;
                    m_MapOfString = m_emptyMap;
                    l = j+lenL;
                }
                else{

                    if( 0 == m_MapOfString[subS])
                    {
                        //cout << "test" <<endl;
                        string subSb = S.substr(l,lenL);
                        while(subSb != subS)
                        {
                            m_MapOfString[subSb] += 1;
                            l += lenL;

                            subSb = S.substr(l,lenL);
                            --count;
                        }

                        m_MapOfString[subSb] += 1;
                        l += lenL;

                        --count;
                    }

                    m_MapOfString[subS] -= 1;

                    ++count;
                }

                    //          pMap(m_MapOfString);
                    //     cout << "l = "<< l<<  "j = " << j<< " "<< "count = " << count<<  "sizeL = " << sizeL << endl;

//               pMap(m_MapOfString);
//               cout << "l = "<< l<<  " j = " << j<< " "<< " count = " << count<<  " sizeL = " << sizeL << endl;


                if(sizeL == count)
                {
                    string subSb = S.substr(l,lenL);

                    m_MapOfString[subSb] += 1;
                    count --;

                    res.push_back(l);

                    l += lenL;

               //pMap(m_MapOfString);

               //cout << "l = "<< l<<  " j = " << j<< " "<< " count = " << count<<  " sizeL = " << sizeL << endl;

                }


            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    //string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
    //vector<string> L = {"fooo","barr","wing","ding","wing"};
    string s("abababab"); 
    vector<string> L = {"a","b","a"};
    //string s("barfoothefoobarman");
    //vector<string> L = {"foo","bar"};
    vector<int> tmp = (S.findSubstring(s, L));
    pVector(tmp);
}
