#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > twoSum(vector<int> &num, int target) {
            auto itb = num.begin();
            auto ite = num.end();
            int ret = *itb+*(ite-1);
            vector<vector<int> > result;
            while(itb<ite-1){
                if(*itb+*(ite-1)==target){
                    vector<int> temp;
                    temp.push_back(*itb);
                    temp.push_back(*(ite-1));
                    result.push_back(temp);
                }
                if(*itb+*(ite-1) > target){
                    ite--;
                }else{
                    itb++;
                }
            }
            return result;
        }
};

int main(){
    Solution s;
    vector<int> num = {0, 1 , 2 , 3 , -1, -2, -3 };
    num = {1,0,-1,0,-2,2};
    sort(num.begin(),num.end());

    vector<vector<int> > i= s.twoSum(num,0);
    for(auto it = i.begin();it!=i.end();it++){
        for(auto it2 = it->begin(); it2!=it->end(); it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }

    return 0;
}


// Here is some Java Code with regarding to my problem
//
//


    public int[] twoSum(int[] numbers, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        //Copy the original array and sort it
        int N = numbers.length;
        int[] sorted = new int[N];
        System.arraycopy(numbers, 0, sorted, 0, N);
        Arrays.sort(sorted);
        //find the two numbers using the sorted arrays
        int first = 0;
        int second = sorted.length - 1;
        while(first < second){
            if(sorted[first] + sorted[second] < target){
                first++;
                continue;
            }
            else if(sorted[first] + sorted[second] > target){
                second--;
                continue;
            }
            else break;
        }
        int number1 = sorted[first];
        int number2 = sorted[second];
        //Find the two indexes in the original array
        int index1 = -1, index2 = -1;
        for(int i = 0; i < N; i++){
            if((numbers[i] == number1) || (numbers[i] == number2)){
                 if(index1 == -1)
                     index1 = i + 1;
                 else
                     index2 = i + 1;
            }
                
        }
        int [] result = new int[]{index1, index2};
        Arrays.sort(result);
        return result;
    }
