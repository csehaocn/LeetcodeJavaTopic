#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            if(s.empty())
                return 0;

            int size = 0;
            string::iterator l,r;
            r = l=s.begin();
            r++;
            size++;

            map<char,string::iterator> mmap;
            mmap[*l] = l;

            while(r!=s.end()){

                if(mmap.find(*r)==mmap.end()){
                    mmap[*r] = r;
                    r++;
                }else{
                    string::iterator m = mmap[*r];
                    while(l!=m){
                        mmap.erase(*l);
                        l++;
                    }
                    mmap[*r] = r;
                    l++;
                    r++;
                }

                if(mmap.size()>size)
                    size=mmap.size();

            }

            return size;
        }
};

int main(){

    Solution s;
    string ss = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    s.lengthOfLongestSubstring(ss);
    cout<<"";
}
