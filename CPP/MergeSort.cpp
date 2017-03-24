#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution{
    public:

    void pVector(const vector<int> &vec){
        if(vec.empty())
            cout<<"empty";
        for(auto it = vec.begin(); it != vec.end(); it++){
            cout << *it << " " ;
        }
        cout<<endl;
    }

    template<class _Compare>
    vector<int> Merge(vector<int> left, vector<int> right, _Compare comp){
        vector<int> result;
        auto itL = left.begin(); 
        auto itR = right.begin(); 
        while(itL !=left.end() && itR != right.end()){
            if( comp(*itL,*itR)){
                result.push_back(*itL);
                itL++;
            }else{
                result.push_back(*itR);
                itR++;
            }
        }
        itL == left.end()?result.insert(result.end(), itR, right.end()): result.insert(result.end(),itL,left.end());
        return result;
    }

    template<class _Compare>
    vector<int> MergeSort(vector<int> arr, _Compare comp){
        vector<int> result;
        int len = arr.size();
        if(len < 2)
            return arr; 
        vector<int> left(arr.begin(),arr.begin()+len/2);
        vector<int> right(arr.begin()+len/2,arr.end());
        result = Merge(MergeSort(left, comp), MergeSort(right, comp), comp);
        return result;
    }

    template<class _Compare>
    vector<int> Heapify(vector<int> arr, int heapSize, int index, _Compare comp){
       while( 2*index < heapSize ){
            int i = comp(arr[2*index+1],arr[index])?2*index+1:index;
            if(2*index+2 <=heapSize){
                i = comp(arr[2*index+2],arr[i])?2*index+2:i;
            }
            if(index != i){
                arr[index]^=arr[i];
                arr[i]^=arr[index];
                arr[index]^=arr[i];
                index = i;
            }else
                break;
       }
       return arr;
    }

    template<class _Compare>
    vector<int> HeapSort(vector<int> arr, _Compare comp){
        for(int index = arr.size()/2-1; index >=0; index--){
            arr = Heapify(arr, arr.size()-1, index, comp);
        }
        for(int index = arr.size()-1; index >=1; index--){
            swap(arr[0],arr[index]);
            arr = Heapify(arr,index - 1, 0, comp);
        }
        return arr;
    }

    template<class RanAccIterator,class _Compare>
        RanAccIterator Partition(RanAccIterator first, RanAccIterator last, _Compare comp){

            auto left = first+1;
            auto right = first+1;
            while(right!=last){
                if(comp(*right,*first)){
                    ++right;
                }else{
                    swap(*right,*left); 
                    ++left;
                    ++right;
                }
            }
            swap(*(left-1),*first);
            return left;
        }

    template<class RanAccIterator,class _Compare>
        void QuickSort(RanAccIterator first, RanAccIterator last, _Compare comp){
            if(last-first < 2)
                return;
            RanAccIterator it = Partition(first, last, comp);
            QuickSort(first,it,comp);
            QuickSort(it,last,comp);
            return;
        }
};

int main(){
    Solution s;
    vector<int> arr = {1,3,4,6,0,-9};
    arr = {1,3,4,6,0,-9};
    cout<<"Mearge Sort:"<<endl;
    arr = s.MergeSort(arr,greater<int>());
    s.pVector(arr);
    sort(arr.begin(),arr.end(),greater<int>());
    s.pVector(arr);
    arr = s.MergeSort(arr,less<int>());
    s.pVector(arr);
    sort(arr.begin(),arr.end(),less<int>());
    s.pVector(arr);
    cout<<"Heap:"<<endl;
    arr = {11,3,4,6,7,9};
    arr = s.Heapify(arr, arr.size()-1, 0, less<int>());
    s.pVector(arr);
    arr = {11,9,8,6,1,0};
    arr = {1,3,4,6,0,-9};
    arr = s.HeapSort(arr,less<int>());
    s.pVector(arr);
    cout<<"Quick Sort:"<<endl;
    arr = {5,3,4,6,7,-9};
    s.QuickSort(arr.begin(), arr.end(), less<int>());
    s.pVector(arr);
    s.QuickSort(arr.begin(), arr.end(), greater<int>());
    s.pVector(arr);
    return 0;
}
