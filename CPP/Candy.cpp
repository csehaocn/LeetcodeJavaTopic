/**************************************************************************
 * 
 *   File :       Candy.cpp
 *   Created:     11/06/13
 *   Author:      Hao Wang
 *
 * ------------------------------------------------------------------------
 *
 * COPYRIGHT AIMLAB UNIVERSITY OF OREGON, 2013.
 * All rights reserved.
 * 
 * ------------------------------------------------------------------------
 *   
 * Revision history:
 *  11/06/13  Hao first issue
 *
 *************************************************************************/

/**************************************************************************
 * Description:  
 *
 * Argument:     
 *
 * Return value:
 *************************************************************************/
#include<vector>
#include<iostream>
#include<cstddef>
#include<deque>
#include<cstdlib>
#include<utility>
using namespace std;

class Solution {
    private:
        pair<int,int> get_neig(int pos, int size){

            if(0 == pos){
                return make_pair(-1,1);
            }
            else if(size-1 == pos){
                return make_pair(pos-1,-1);
            }
            else{
                return make_pair(pos-1,pos+1);
            }

        }

    public:

        int candy(vector<int> &ratings) {

            if(0==ratings.size())
                return 0;

            if(1==ratings.size())
                return 1;

            int *NCandy =(int*)malloc(sizeof(int)*ratings.size());

            for (int i = 0; i < ratings.size(); i++){
                NCandy[i] = 0;
            }

            deque<int> tag = deque<int>();

            for(vector<int>::iterator it = ratings.begin(); it != ratings.end(); it++){

                vector<int>::difference_type pos = it - ratings.begin(); 
                
                pair<int,int> neigbour = get_neig(pos, ratings.size());

                bool lowest = true;

                int pos_n = neigbour.first;

                if (-1 != pos_n){
                    if(*(ratings.begin()+pos_n) < *(ratings.begin()+pos) ){
                        lowest = false;
                    }
                }

                pos_n = neigbour.second;

                if (-1 != pos_n){
                    if(*(ratings.begin()+pos_n) < *(ratings.begin()+pos) ){
                        lowest = false;
                    }
                }

                if(lowest){
                    NCandy[pos] = 1;
                    tag.push_back(pos); 
                }
            }

            while(!tag.empty()){
                int pos = tag.front();
                tag.pop_front();
                pair<int,int> neigbour = get_neig(pos, ratings.size());

                int pos_n = neigbour.first;

                if (-1 != pos_n){
                    if(*(ratings.begin()+pos_n) > *(ratings.begin()+pos) && NCandy[pos_n] <= NCandy[pos]){
                        NCandy[pos_n] = NCandy[pos]+1;
                        tag.push_back(pos_n);
                    }
                }

                pos_n = neigbour.second;

                if (-1 != pos_n){
                    if(*(ratings.begin()+pos_n) > *(ratings.begin()+pos) && NCandy[pos_n] <= NCandy[pos]){
                        NCandy[pos_n] = NCandy[pos]+1;
                        tag.push_back(pos_n);
                    }
                }
            }
            int result = 0;
            for (int i = 0; i < ratings.size(); i++){
                result += NCandy[i];
            }

            delete [] NCandy;

            return result;

        }
};

int main(){
    
    Solution s = Solution();

    vector<int> input = {4,2,3,4,1};

    cout << s.candy(input);

    return 0;
}
