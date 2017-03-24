class Solution {
    
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
        
        vector<vector<string> > res;
        
        int dLen = dict.size();
        
        unordered_map<string, unordered_set<string> > v_AdjList;
        unordered_map<string, int> v_Dist;
        
        for(auto iter = dict.begin(); iter != dict.end(); ++iter){
            v_AdjList[*iter] = unordered_set<string>();
            v_Dist[*iter] = -1;
        }
        
        for(auto iter_a = dict.begin(); iter_a != dict.end(); ++iter_a)
        for(auto iter_b = iter_a; iter_b != dict.end(); ++iter_b){
            if(adj(*iter_a, *iter_b))
                v_AdjList[*iter_a].insert(*iter_b);
                v_AdjList[*iter_b].insert(*iter_a);
        }
        /*
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
            if(v_Dist[end] == pLen)
                break;
            // front of path
            string front = path.back();
            list<string> &neigh = v_AdjList[front];
            for(auto iter = neigh.begin(); iter != neigh.end(); ++ iter){
                // if not visited
                if(v_Dist[*iter] == -1){
                    v_Dist[*iter] = pLen + 1;
                }
                if(v_Dist[*iter] == pLen + 1){
                    path.push_back(*iter);
                    pathes.push(path);
                }
                if(*iter == end){
                    res.push_back(path);
                }
            }
            
        }
        */
        return res;
    }
};
