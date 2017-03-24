#include<iostream>
#include<vector>
using namespace std;
    template<class RanAccIterator>
    void pVector(RanAccIterator first, RanAccIterator last){
        for(auto it = first; it != last; it++){
            cout<< *it << " ";               
        }
        cout<<endl;
    }

class Solution{
public:

    template<class RanAccIterator, class _Compare>
    RanAccIterator Partition(RanAccIterator first, RanAccIterator second, _Compare comp){
        RanAccIterator left, right; 
        left = right = first+1;
        while(right!=second){
            if(comp(*first,*right)){
                swap(*left,*right);
                left++;
                right++;
            }else{
                right++;
            }
        }
        swap(*(left-1),*first);
        return left;
    } 

    template<class RanAccIterator>
    RanAccIterator KthSmallest(RanAccIterator first, RanAccIterator last, int k){
        if(last - first < k || 0 == k)
            return last;
        auto it = Partition(first, last, greater<int>());
        if(it-first == k){
            return it-1;
        }else if(it-first < k){
            return KthSmallest(it,last,k-(it-first));
        }else{
            return KthSmallest(first, it, k);
        }
    }

};

int main(){
    vector<int> tem = {5,4,7,9,2,10,0};
    Solution s;
    auto it = s.KthSmallest(tem.begin(), tem.end(), 3);
    cout << *it << endl; 
    return 0;
}
