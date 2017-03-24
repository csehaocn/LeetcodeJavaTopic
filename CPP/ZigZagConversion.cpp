// Output limit exceed in the second program.
// Solved, problem is 
//  while(index < len) did not judge the boarder.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{

    public:

        string convert(string s, int nRows) {
            string result;
            vector<string> sVec= vector<string>(nRows,""); 
            int size = 0;
            while(size < s.size()){
                int subSize;
                nRows == 1 ?subSize = 1 : subSize = 2*nRows-2;
                string subS = s.substr(size,subSize); 
                cout << subS << endl;
                size+=subS.size();
                for(int i = 0; i < nRows; i++){
                    if(i<subS.size())
                        sVec[i].push_back(subS[i]);
                    if(i!=nRows-1 && i !=0 && 2*(nRows-1)-i < subS.size())
                        sVec[i].push_back(subS[ subS.size() -1 - i]);
                }
            }
            for(auto it = sVec.begin(); it != sVec.end(); it ++){
                result  = result + *it;
            }
            return result;
        }


};

class Solution_B {
public:
    string convert(string s, int nRows) {
        
        string result;
        
        int len = s.size();
        
        if(0 == len)
            return result;
        
        int jump;

        cout << nRows<< endl;
        
        if( 1 == nRows)
            jump = 1;
        else
            jump = 2*nRows-2;
        
        for(int i = 0; i!= nRows; ++i)
        {
            
            if(0 == i || nRows-1 == i)
            {
                int index = i;
                while(index < len)
                {
                    result.push_back(s[index]);
                    index += jump;
                }
            }
             else
            {
                int index = i;
                int index_b = jump - i;
                while(index < len || index_b < len)
                {
                    if(index < len)
                    {
                    result.push_back(s[index]);
                    index += jump;
                    }
                    if(index_b < len)
                    {
                    result.push_back(s[index_b]);
                    index_b += jump;
                    }
                }
                /*

                while(index < len)
                {
                    result.push_back(s[index]);
                    index += jump;
                    result.push_back(s[index_b]);
                    index_b += jump;
                }  

                  */
            }

        }
        
        return result;
        
    }
};

int main(){
    //int end;
    Solution_B s;
    string r = s.convert("ABCDEFGHIJK", 11);
    //r = s.convert("ABCDEFGHIJK", 1);
    cout << r ;
    //end = 1;
    return 0;
}
