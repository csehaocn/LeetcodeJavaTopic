// Since local function is not feasible in C++, the transform function is not working well locally if no member variable is set.
class Solution {
  
public:
    vector<string> anagrams(vector<string> &strs) {
        
        vector<string> res;
        
        int len = strs.size();
        
        if(0 == len)
            return res;
        
        // map of string and it's set of index
        map<string, vector<int> > myMap;
        
        for(int i = 0; i != len; ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(myMap.find(s)==myMap.end())
            {
                myMap[s]=vector<int>();
            }
            myMap[s].push_back(i);
            
        }
        
        for(auto it = myMap.begin(); it != myMap.end(); ++it){
            if(it->second.size()>1){
                
                vector<int> vIndex = it->second;
                for(auto it2 = vIndex.begin(); it2 != vIndex.end(); it2++){
                    res.push_back(strs[*it2]);
                }
                
                /*
                string op_find(int i){return strs[i];}
                vector<string> tmp;
                tmp.resize(vIndex.size());
                transform(vIndex.begin(),vIndex.end(),tmp.begin(), tmp.end(), op_find);
                */
            }
        }
        
        return res;
    }
};
