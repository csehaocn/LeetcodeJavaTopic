// Use quote assign the wrong variable is a very stupid mistake and should be avoided.
//
//
// Becarefull of how this code went wrong if you adjust l after you find r.
//
// for example bba and ba 
// the l = 0, and it find the first b, then it stop 
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

class myclass {
public:
    bool operator() (pair<int, int> l, pair<int, int> r){
        return l.second - l.first < r.second - r.first;
    }
} myobj;

bool myfun (pair<int, int> l, pair<int, int> r){
        return l.second - l.first < r.second - r.first;
}


class Solution {

    bool myfn(pair<int, int> l, pair<int, int> r){ return l.second - l.first < r.second - r.first; }
    

public:
    string minWindow(string S, string T) {

        int lenS = S.size();
        int lenT = T.size();

        if (0 == lenT)
        {
            return string("");
        }

        if (0 == lenS)
        {
            return string("");
        }

        map<char, int> T_map;

        vector<pair<int, int> > minVec;

        for (int i = 0; i != lenT; ++i){
            T_map[T[i]] = 0;
        }
        for (int i = 0; i != lenT; ++i){
            T_map[T[i]]++;
        }

        int count = 0;

        int l = 0;

        for (int j = 0; j != lenS; ++j){

            if (T_map.find(S[j]) != T_map.end())
            {
                T_map[S[j]]--;
                if (T_map[S[j]] >= 0 )
                    count++;
            }

            if (lenT == count)
            {
                //cout << T_map['b'] << endl;
                //cout << l << j << endl;
                //cout << T_map['a'] << endl;
                while ( l < lenS )
                {
                    if( T_map.find(S[l]) != T_map.end())
                    {
                        ++T_map[S[l]];
                        if(T_map[S[l]] == 1)
                        {
                           count--;
                           break;
                        }
                    }
                    ++l;
                }
                
                //cout << l << j << endl;

                minVec.push_back(make_pair(l, j));
                l++;
            }

        }

        if(minVec.empty())
        {
            return string("");
        }
        cout << minVec.size() << endl;
        //cout << minVec[0].first << minVec[0].second << endl;
        //cout << minVec[1].first << minVec[1].second << endl;

        auto iter = min_element(minVec.begin(), minVec.end(), myfun);

        return string(S.begin() + iter->first, S.begin() + iter->second + 1);

    }
};

int main(){
    Solution S;
    cout << S.minWindow(string("ababa"), string("aaa"));
}
