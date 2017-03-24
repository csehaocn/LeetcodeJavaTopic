#include<unordered_set>
#include<vector>
#include"util.hpp"
#include<unordered_map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
/*
class Solution2{
    
bool adj(const string & a, const string &b){
    
    int aLen = a.size();
    int bLen = b.size();
    
    if(aLen != bLen)
        return false;
    
    int dist = 0;
    for(int i = 0; i != aLen; ++i){
        if(a[i] != b[i]) ++dist;
        if(dist > 1) return false;
    }
    return dist == 1;
    
}    
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        dict.insert(start);
        dict.insert(end);

        vector<vector<string> > res;
        
        int dLen = dict.size();
        
        unordered_map<string, unordered_set<string> > v_AdjList;
        unordered_map<string, int> v_Dist;
        
        for(auto iter = dict.begin(); iter != dict.end(); ++iter){
            v_AdjList[*iter] = unordered_set<string>();
            v_Dist[*iter] = -1;
        }

        
        for(unordered_set<string>::iterator iter_a = dict.begin(); iter_a != dict.end(); ++iter_a)
        {
        for(unordered_set<string>::iterator iter_b = iter_a; iter_b != dict.end(); ++iter_b){
            if(adj(*iter_a, *iter_b))
            {
                v_AdjList[*iter_a].insert(*iter_b);
                v_AdjList[*iter_b].insert(*iter_a);
            }
        }
        }

        queue <vector<string> > pathes;
        vector<string> tmp;
        tmp.push_back(start);
        v_Dist[start] = 0;
        pathes.push(tmp);

        while(!pathes.empty()){
            vector<string> path = pathes.front();
            pathes.pop();
            int pLen = path.size();
            //break if not possible to find.
            //pVector(path);
            ////cout << pLen << v_Dist[end] << endl;       
            if(v_Dist[end] == pLen)
                break;
            // front of path
            string front = path.back();
            unordered_set<string> neigh = v_AdjList[front];
            for(auto iter = neigh.begin(); iter != neigh.end(); ++ iter){
                //cout << "neigh: " << *iter << endl; 
                // if not visited
                if(v_Dist[*iter] == -1){
                    v_Dist[*iter] = pLen + 1;
                }
                if(v_Dist[*iter] == pLen + 1){
                    path.push_back(*iter);
                    pathes.push(path);
                    // wtf forget about this 
                    path.pop_back();
                }
                if(*iter == end){
                    path.push_back(end);
                    res.push_back(path);
                    path.pop_back();
                }
            }
            
        }
        return res;
    }
};
*/

class Solution3 {
    
typedef unordered_set<string>::iterator strIter;

unordered_set<strIter> adj(string s, unordered_set<string> &dict){
    unordered_set<strIter> res;
    int sLen = s.size();
    string sCopy = s;
    for(int i = 0; i != sLen; ++i){
        for(char c = 'a'; c <= 'z'; c++){
            if(s[i] != c){
                sCopy[i] = c;
                auto it = dict.find(sCopy);
                if(it != dict.end())
                    res.insert(it);
            }
        }
    }
    
    return res;
}

void DFS_path(strIter& curr, strIter& target, unordered_map<strIter, vector<strIter> >& pathMap, vector<string> path, vector<vector<string> > res){
    if(path.back() == *target){
        reverse(path.begin(), path.end());
        res.push_back(path);
        reverse(path.begin(), path.end());
        return ;
    }
    
    vector<strIter> next = pathMap[curr];
    for(auto iter = next.begin(); iter != next.end(); ++iter){
        path.push_back(**iter);
        DFS_path(*iter, target, pathMap, path, res);
        path.pop_back();
    }
    
}


public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        vector<vector<string> > res;
        int len = dict.size();
        if( 0 == len)
            return res;
        
        dict.insert(start);
        dict.insert(end);
        strIter startIter = dict.find(end);
        auto endIter = dict.find(end);
      
        
        //unordered_set<string> d;
        //unordered_set<unordered_set<string>::iterator> ss;
        //ss.insert(d.begin());
        //unordered_set<strIter> v_levelVec;
        //unordered_set<strIter> &tmp = v_levelVec[0];
        //tmp.insert(startIter);
        //v_levelVec.insert(startIter);
/*        
        unordered_map<strIter, vector<strIter> > pathMap;
        for(auto it = dict.begin(); it != dict.end(); ++it){
            //pathMap[it];
            //= vector<strIter>;
        }
        int level = 0;
        while(1){
            
            unordered_set<strIter> & c_level = level%2?v_levelVec[0]:v_levelVec[1];
            unordered_set<strIter> & n_level = level%2?v_levelVec[1]:v_levelVec[0];
            
            n_level.clear();
            // possible bool flag for reach the end
            for(auto cIter = c_level.begin(); cIter != c_level.end(); cIter++){
                unordered_set<strIter> ss = adj(**cIter, dict);
                for(auto ssIter = ss.begin(); ssIter != ss.end(); ++ssIter){
                    pathMap[*ssIter].push_back(*cIter);
                }
                n_level.insert(ss.begin(), ss.end());
                dict.erase(*cIter);
            }
            
            if(n_level.find(endIter) != n_level.end()){
                //found, trace back
                
                vector<string> path;
                
                DFS_path(endIter, startIter, pathMap, path, res);
                
                break;
            }
            else{
                ++level;
                // next level
            }
            
        }
*/        
        
        return res;
        
    }
};

class Solution {
    
typedef unordered_set<string>::iterator strIter;

unordered_set<string> adj(string s, unordered_set<string> &dict){
    //cout << "In adj : " << s << endl;
    unordered_set<string> res;
    int sLen = s.size();
    string sCopy;
    for(int i = 0; i != sLen; ++i){
        sCopy = s;
        for(char c = 'a'; c <= 'z'; c++){
            if(s[i] != c){
                sCopy[i] = c;
                auto it = dict.find(sCopy);
                if(it != dict.end())
                    res.insert(*it);
            }
        }
    }

    //cout << "In adj, adj size : " << res.size() << endl;
    
    return res;
}


void DFS_path(string& target, unordered_map<string, vector<string> >& pathMap, vector<string>& path, vector<vector<string> >& res){


    if(path.back() == target){
        reverse(path.begin(), path.end());
        res.push_back(path);
        reverse(path.begin(), path.end());
        return ;
    }
    
    //cout << path.back() << endl;
    vector<string>& next = pathMap[path.back()];
    //cout << next.size() << endl;
    for(auto iter = next.begin(); iter != next.end(); ++iter){
        path.push_back(*iter);
        DFS_path(target, pathMap, path, res);
        path.pop_back();
    }
    return;
    
}


public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        vector<vector<string> > res;
        int len = dict.size();
        if( 0 == len)
            return res;
        
        dict.insert(start);
        dict.insert(end);
        
        vector<unordered_set<string> > v_levelVec(2,unordered_set<string>()); 
        v_levelVec[0].insert(start);
        dict.erase(start);
    //    cout << v_levelVec[0].size() << endl;
        unordered_map<string, vector<string> > pathMap;
        for(auto it = dict.begin(); it != dict.end(); ++it){
            pathMap[*it] = vector<string>();
        }
        int level = 0;
        
        while(1){

   //         cout << "start" << endl;
            
           unordered_set<string> & c_level = level%2?v_levelVec[1]:v_levelVec[0];
           unordered_set<string> & n_level = level%2?v_levelVec[0]:v_levelVec[1];
            
    //        cout << "Curr Level Size:" << c_level.size() << endl;
     //       cout << "Next Level Size:" << n_level.size() << endl;
            if(c_level.empty())
                break;

            n_level.clear();
            // possible bool flag for reach the end

            for(unordered_set<string>::iterator cIter = c_level.begin(); cIter != c_level.end(); cIter++){
               dict.erase(*cIter);
            }
            for(unordered_set<string>::iterator cIter = c_level.begin(); cIter != c_level.end(); cIter++){
               dict.erase(*cIter);
               string s = *cIter;
               cout << s << endl;
               unordered_set<string> ss = adj(*cIter, dict);
                cout << "ss.size: " << ss.size() << endl;
                for(auto ssIter = ss.begin(); ssIter != ss.end(); ++ssIter){
                    cout << "ss " << *ssIter << " push back " << *cIter << endl;
                    pathMap[*ssIter].push_back(*cIter);
                }

                cout << "ss.size: " << ss.size() << endl;
                n_level.insert(ss.begin(), ss.end());
            }

            for(unordered_set<string>::iterator cIter = c_level.begin(); cIter != c_level.end(); cIter++){
 //                   cout<< "pathMap " << *cIter << " : "; pVector(pathMap[*cIter]);

        }
  //          cout << "Next Level Size:" << n_level.size() << endl;

            if(n_level.find(end) != n_level.end()){
//                cout << "end path map : "; pVector(pathMap[end]);
                //found, trace back
                vector<string> path;
                path.push_back(end);
                DFS_path(start, pathMap, path, res);
                break;
            }
            else{
                ++level;
                // next level
            }
            
        }
        
        return res;
        
    }
};

// Notice in the 3rd solution, the erase dictionary should be a indepentent loop with the path finding. No matter you put erase in curent level or next level.
// Put erase in current level loop, makes the word in one level could find each other, the ---> or <--- arrows. 
// Put erase in next level loop, make the first iteration in current level erase the next level word, makes other path
// |  |
// |  |
//  \/
//  like this, the right path of it could not find because adj use the dictionary as well.

int main(){
    Solution s;
//    string start = "hit";
 //   string end = "cog";
  //  unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    string start = "hot";
    string end = "dog";
    unordered_set<string> dict = {"hot""dog"};
    vector<vector<string> > res = s.findLadders(start, end, dict);
    cout << "res size : " << res.size() << endl;
    //pVector(res[0]);
    //pVector(res[1]);
    return 0;
}


