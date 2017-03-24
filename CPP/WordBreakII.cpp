#include"util.hpp"
#include<iostream>
#include<vector>
#include<string>
#include <unordered_set>
using namespace std;

class Solution {

public:

    vector<string> wordBreak(string s, unordered_set<string> &dict) {

        vector<string> result = vector<string>();
        
        if(dict.empty())
        	return result;
        
        int min = dict.begin()->size();
        int max = 0;
        
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++){
        
        int size = it->size();
        
        size<min?min=size:NULL;
        
        size>max?max=size:NULL;
    
    	}
        vector<vector<const string*>> DPList = vector<vector<const string*>>(s.size(),vector<const string*>());
        
        for(int i =0; i<s.size(); i++){
        
        	for(unordered_set<string>::iterator it = dict.begin(); it!= dict.end(); it++){
        
            	if (i+1==it->size()&& 0 == s.compare(i+1-it->size(),it->size(),*it)){
            		//cout<<i<<"true";
            		DPList[i].push_back(&(*it));
            	}
            
                if (i+1>it->size() && 0 == s.compare(i+1-it->size(),it->size(),*it) && !DPList[i-it->size()].empty()){
                	//cout<<i+1<<" "<<it->size()<<" ";
                	DPList[i].push_back(&(*it));
        		}
        	}
        
        }

	vector<const string*> test = DPList[3];

		for(vector <const string*>::iterator it = test.begin(); it < test.end(); it++){
    		cout<<**it<<" ";
		}
	

    vector<vector<string>> ConstructList = vector<vector<string>>(s.size(),vector<string>());

    
    for(int i =s.size()-1; i>=0; i--){
        cout<<i<<endl;
    
    	for(vector<const string*>::iterator it = DPList[i].begin(); it < DPList[i].end(); it++){

            int size = (*it)->size();
            int pre_index = i-size+1;
            //cout<<i<<" "<<pre_index<<endl;

            if(s.size()-1 == i){

                ConstructList[pre_index].push_back((**it));    

            }else{

    	        for(vector<string>::iterator it2 = ConstructList[i+1].begin(); it2 < ConstructList[i+1].end(); it2++){

                    ConstructList[pre_index].push_back((**it)+" "+(*it2));    

                }
            }

    	    for(vector<string>::iterator it2 = ConstructList[i].begin(); it2 < ConstructList[i].end(); it2++){

                cout<<*it2<<" ** ";

            }
                cout<<endl;
               
		}
	}
    
    /*
    
    string curr = string(**it);
    
    if(0 == i-DPList[i].size())
    ConstructList[i].push_back(curr);
    
    for(vector<string>::iterator it2 = pre.begin(); it2 < pre.end(); it2++){
    
    string pp = string(*it2);
    
    string tt =  string(pp+curr);
    
    ConstructList[i].push_back(tt);
    
    }
    
    
    */
    
    
    result = ConstructList[0];
        
    return result;
    
	}
};

class Solution2 {
    
    vector<vector<string> > DPArr;
    vector<int> DPSignArr;
    
    int wordBreakHelper(string &s, int start, unordered_set<string> &dict){
       
       if( start > s.size()){
           //Not working
           return 0;
       }else if(start == s.size() ){
           // Working
           return 1;
       }else{
           // Not reach end, need to decide.
           if(DPSignArr[start] == 1){
               // working
               return 1;
           }else if(DPSignArr[start] == 0){
               // not working
               return 0;
           }else{
               // -1, not sure
               for(auto iter = dict.begin(); iter != dict.end(); iter++){
                   //Iterate through all dict;
                   if(s.compare(start, iter->size(), *iter) == 0){
                       // Match with the dict;
                       if(wordBreakHelper(s, start+iter->size(), dict)){
                            //if working
                            // work on the sign.
                            DPSignArr[start] = 1;
                            // record the dict.
                            if(start+iter->size() == s.size()){
                                // working because reaches end
                                DPArr[start].push_back(*iter);
                            }
                            else{
                                vector<string>& stringVec = DPArr[start + iter -> size()];
                                for(auto it2 = stringVec.begin(); it2 != stringVec.end(); ++it2){
                                    DPArr[start].push_back( string(*iter) + " " + *it2);    
                                }
                            }
                       }
                       
                   }
               }
               
               // return the current status;
               return DPSignArr[start];
           }
       }
       
    }
    
public:

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
        vector<string> res;
        int len = s.size();
        if(0 == len)
            return res;
        
        DPArr = vector<vector<string> >(len, vector<string>());
        DPSignArr = vector<int>(len, -1);
        
        int ret = wordBreakHelper(s, 0, dict);
        
        if(0 == ret){
            // no result
            return res;
        }else{
            return DPArr[0];
        }
        
    }
};

class Solution3 {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.length();
        vector<vector<string>> partial_sentences(n + 1);
        partial_sentences[n] = {""};
        for (int i = n - 1; i >= 0; i--) {
            //vector<string> sentences = {}; 
        // iterate through the dictionary
        for(auto iter = dict.begin(); iter != dict.end(); ++iter){
            int dictLen = iter->size();
            // the length of dict word
            
            // if the dict fall out size of range   
            if(i + dictLen > n){
                // nothing get changed.
            }
            else{
                // it string match
                if(s.compare(i, dictLen, *iter) == 0)
                {
                    // partial sentence at i + dictLen
                    vector<string> &iPDictLen = partial_sentences[i+dictLen];
                    cout << i+dictLen << endl; 
                    pVector(iPDictLen);
                    for(auto partialIter = iPDictLen.begin(); partialIter != iPDictLen.end(); ++partialIter)
                    {
                        partial_sentences[i].push_back(*iter + " "+ *partialIter) ;
                    }
                }
            }
        } 
    }          
        return partial_sentences[0];
    }
};

int main(){

	Solution3 sol;
    string str("catsanddog");
    unordered_set<string> dict({"cat","cats","and","sand","dog"});

	vector<string> result = sol.wordBreak(str, dict);
    cout << result.size() << endl;
    cout << result[0] << endl;
    cout << result[1] << endl;
	return 0;
}
