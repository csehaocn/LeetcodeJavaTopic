#include<iostream>
#include<vector>
#include"util.hpp"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        
        vector<string> res;
        int size = words.size();
        if( 0 == size){
            res.push_back(string(L,' '));
            return res;
        }
        
        if( 1 == size){
            res.push_back(words[0]+ string(L-words[0].size(), ' '));
            return res;
        }
            
        int len = 0;    
        int l = 0;
            
        for(int i = 0; i != size; ++i)
        {

//            cout << "len: " << len << endl;
            if(len + words[i].size() > L){

                len --;
                int n_word = i - l;
//                cout << "n_word: " << n_word << endl;
                int diff = L - len;
//                cout << "diff: " << diff << endl;

                string tmp;
                tmp += (words[l]);
                if( 1 == n_word){
                    tmp+= ( string(L-len, ' '));
                }
                else{
                    // greater than average space wide, +1
                    int space_wide = diff/(n_word-1);
                    int mod = diff%(n_word-1); 
                    //cout << "space_wide: " << space_wide << endl;
                    //cout << "mod: " << mod << endl;

                    if(1 == n_word)
                    {
                            tmp += string(diff, ' ');
                    }
                    else
                    {
                        for(int j = l+1; j != i; ++j){

                            tmp += string(space_wide+1, ' ');
                            if(mod)
                            {
                                tmp += " ";
                                --mod;
                            }
                            tmp += words[j];

                        }

                    }
                }
                res.push_back(tmp);
                len = 0;
                l = i;
            }
            len += words[i].size()+1;
        }
        //cout << "len" << len << endl; 
        if(len){
            string tmp;
            for(int j = l; j != size-1; ++j){
                tmp += words[j]+string(1, ' ');
            }
            tmp += words[size-1];
            tmp += string(L-tmp.size(), ' ');
            res.push_back(tmp);
        }
                /*
        cout << res.size() << endl;
        cout << res[0] << endl;
        cout << res[1] << endl;
        cout << res[2] << endl;
                */
        return res;
        
    }
};

int main()
{
    Solution S;
    vector<string> words;
    /*
    */
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("e");
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("exmaple");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification.");
    words.push_back("Listen");
    words.push_back("to");
    words.push_back("many,");
    words.push_back("speak");
    words.push_back("to");
    words.push_back("a");
    words.push_back("few.");
    vector<string> s = S.fullJustify(words, 16);
    for(auto it = s.begin(); it != s.end(); ++it)
    {
       cout <<  *it << endl; 
    }
    return 0;
}
