class Solution {

    pair<int, int> searchRangeAux(int A[], int n, int target){
        if(0 == n)
            return make_pair(0, -1);
        
        if(1 == n){
            if(A[0] == target){
                return make_pair(0,0);
            }
            else{
                return make_pair(-1,-1);
            }
        }
        
        int pivot = (n+1)/2;
        
        pair<int,int> l = searchRangeAux(A, (n+1)/2, target);
        
        pair<int,int> r = searchRangeAux(A+(n+1)/2, n-(n+1)/2, target);

        if(l.second == -1 && r.second == -1){
            return make_pair(-1,-1);
        }
        else if(l.second == -1)
        {
            return make_pair(r.first+(n+1)/2, r.second+(n+1)/2);
        }
        else if(r.second == -1)
        {
            return make_pair(l.first, l.second);
        }
        else
        {
            return make_pair(l.first, r.second+(n+1)/2);
        }
        
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> res;
        pair<int, int> p = searchRangeAux(A, n, target);
        res.push_back(p.first);
        res.push_back(p.second);
        return res;
        
    }
    
};
