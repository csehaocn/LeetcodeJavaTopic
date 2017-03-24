// 1. The symetric situation must consider when left is the head, i.e. the right part can be longer

// 2. Line 79
    //right = curr+lenArr[2*center-curr];
    //left = curr-lenArr[2*center-curr];
// this first logic is not right
/*
      Curr would be at most as r, it not say img can not be longer 
                     center
             l   img     |    curr  r
             |    |      |     |    |
      <----------------------------------------->
                  |       <--------->
          <--------------->
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){

        string myS;
        vector<int> PalSize; 
        myS.push_back('^');
        myS.push_back('#');
        for(string::iterator sIt = s.begin(); sIt != s.end(); sIt++){
            myS.push_back(*sIt);
            myS.push_back('#');
        }
        myS.push_back('$');
        string::iterator c = myS.begin(), r = myS.begin();
        for(string::iterator cit = myS.begin(); cit!= myS.end(); cit++){
            int range; 
            r > cit?range = min(int(r-cit),*(PalSize.end()-2*((int)(cit-c)))):range = 0;
            while(*(cit+range+1)== *(cit-range-1))
                range++;
            if(cit+range > r){
                c = cit;
                r = cit+range;
            }
            PalSize.push_back(range);
        }
        vector<int>::iterator m = max_element(PalSize.begin(), PalSize.end());
        return s.substr((m-PalSize.begin() - 1 - *m)/2, *m);
    }
};

class Solution_B{
public:
    string longestPalindrome(string s) {
        
        string result;
        int len = s.size();
        if(0 == len)
            return result; 
        
        string auxS;
        
        for(int it = 0; it !=len; ++it){
            auxS.push_back('#');
            auxS.push_back(s[it]);
        }
        auxS.push_back('#');

        int auxLen = 2*len +1;

        vector<int> lenArr(auxLen);
        lenArr[0]=0;
        lenArr[1]=1;
        
        int curr = 2;
        int center = 1;
        int r = 2;
        
        while(curr < auxLen){
            cout << curr << " " << r << endl;;
            int right;
            int left;
            if(curr>= r){
                // expand one by one
                right = curr+1;
                left = curr -1;
                while(right < auxLen && left >=0 && auxS[right] == auxS[left]){
                    ++right; 
                    --left;
                }
                right--;
                left++;
                lenArr[curr]=right-curr;

                if(right >= r)
                {
                    center = curr;
                    r = right;
                }
            }
            else{
                right = min(r, curr+lenArr[2*center-curr]);
                left = 2* curr - right;
                //right = curr+lenArr[2*center-curr];
                //left = curr-lenArr[2*center-curr];
            }


            ++curr;
        }
        
        int span = -1;
        int index;
        for(int i = 0; i!=2*len+1; ++i)
        {
            cout<<lenArr[i];
            if(span < lenArr[i])
            {
                span = lenArr[i];
                index = i;
            }
        }
        
        result = string(s.begin()+(index-span)/2, s.begin()+(index+span)/2); 
        return result;
    }
};

int main(){
    //string testS = "aaabaaaa";
    string testS = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    //testS = "a";
    //string testS = "ccc";
    Solution_B S;
    cout<<S.longestPalindrome(testS);
    return 0;
}
