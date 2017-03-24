#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> KMPSTD(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
    vector<int> matches;

    if(K.size() == 0)
    {
        matches.push_back(0);
        return matches;
    }
    for(int i = 1; i <= K.size(); i++)
    {
        int pos = T[i - 1];
        while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }

    int sp = 0;
    int kp = 0;
    while(sp < S.size())
    {
        while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == K.size()) matches.push_back(sp - K.size());
    }

    return matches;
}

vector<int> KMP(string S, string K){
    vector<int> result;

    if(S.empty()||K.empty())
        return result;

    vector<int> pi(K.size(),0);

    for(int i = 0; i!=K.size()-1; i++){
       int q = pi[i];
       do{
            if(K[i+1] == K[q+1-1]){
                pi[i+1] = q+1;
                break;
            }
            else
                q = pi[q-1];
       }while(0!=q);
    }

    int q = 0;
    for(int i = 0; i!=S.size(); i++){
    //        cout<<i<<" "<<q<<" "<<S[i]<<" "<<K[q]<<endl;
        do{
            if(S[i] == K[q]){
                if(q == K.size()-1){
    //                cout<<"m1"<<endl;
                    result.push_back(i-q);
                    q = pi[q-1];
                }else{
                    q++;
                }
    //            cout<<"break"<<endl;
                break;
            }
            else{
                q = pi[q-1];
            }
        }while(q!=0);
    }

    return result;

}

int main(){

    vector<int> matches =  KMP("xyxxyxyxyyxyxyxyyxyxyxxy", "xyxyyxyxyxx");
    //vector<int> matches =  KMP("xyxyyxyxyxx", "xyxyyxyxyxx");
    matches =  KMP("", "");
    matches =  KMP("AABAACAADAABAAABAA", "AABA");
    matches =  KMP("ABABABCABABABCABABABAC", "ABABAC");

    for(auto it = matches.begin(); it!=matches.end(); it++){
        cout<<*it<<" ";
    }

}
