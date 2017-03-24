// The problem of my solution come with mostly find index of the number in the origninal array
//      1. Consider the two the same numbers.
//      2. Consider left and right position.
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> numbers_back = vector<int>(numbers);
        sort(numbers.begin(),numbers.end());
        vector<int>::iterator itl = numbers.begin();
        vector<int>::iterator itr = numbers.end()-1;
        vector<int> result;
        while(1)
        {
            // paste test
            int sum = *itl + * itr;
            if(sum == target)
            {
                int index_l=-1;
                int index_r;
                for(vector<int>::iterator it = numbers_back.begin(); it!=numbers_back.end(); ++it)
                {
                        if(index_l == -1){
                            if(*it == *itl) index_l = it-numbers_back.begin()+1;
                        }
                        if(*itl != *itr || *itl==*itr && -1 != index_l){
                            if(*it == *itr) index_r = it-numbers_back.begin()+1;
                        }
                }
                if(index_l > index_r) swap(index_l, index_r);
                result.push_back(index_l);
                result.push_back(index_r);
                return result;
            }
            else if(sum > target){
                --itr;
            }
            else
            {
                ++itl;
            }
        }
    }
};

int main(){
    std::vector<int> vi;
    return 0;
}
