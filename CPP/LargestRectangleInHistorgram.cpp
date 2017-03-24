//
//  Solution is tricky and hard to understand. Here is the explaination and proof of some important lemma.
//  Example, 
//
//                  #
//          #     # #
//        # #   # # #
//        # # # # # #
//      # # # # # # #
//      # # # # # # # #
//
//      2 4 5 3 4 5 6 1
//
//Index 0 1 2 3 4 5 6 7     
//
//  1. for each possibl largest rectangle, the area is to be decided by a low height, i.e. ceiling height. And left and right boundary that is lower than the ceiling height. The ceiling height can be and should be all the numbers in the array.
//  For example, for ceiling height 3, the left and right boundary is index 0 and 7 with height 2 and 1. They are the first lower number they ll meet to the left and right. 
//
//  2. The algorithm is to find the boundary for each ceiling height, using ..... ehh a stack.
//
//  3. A loop invariant, the number in the stack is always increasing. And for each number a_{i} in the stack, the number a_{i-1} is its left boundary. For example, for index 3 height 3, in its left part, all the indexs with higher height are popped out. The area of them are calculated.   
//                  #                           #                           #   
//          #     # #                   %     # #                   #     # #   
//        # #   # # #                 # %   # # #                 % %   # # #   
//        # # # # # #                 # % # # # #                 % % # # # #   
//      # # # # # # #               # # % # # # #               # % % # # # #   
//      # # # # # # # #             # # % # # # # #             # % % # # # # # 
//                                                                              
//      2 4 5 3 4 5 6 1             2 4 5 3 4 5 6 1             2 4 5 3 4 5 6 1 
//                                                                              
//Index 0 1 2 3 4 5 6 7       Index 0 1 2 3 4 5 6 7       Index 0 1 2 3 4 5 6 7 
//                            
//                            Index 2, higher than 3      Index 1, higher than 3.
//
//    Therefore, the index that is smaller than current index in the stack is the first number that is smaller than 3 to the left.
//    4. When keep going to index 7, height 1. Since for any number, it will pop out the number in the stack that is bigger than it. When 3 is popped out, it is just the moment it met the first number that is smaller than 3 to the right. In this case 1, therefore, the index 0 and 7 combined with the height 3 will generate the area for index 3. 
//
//                       #   
//               #     # #   
//             # #   # # #   
//             # # # # # #   
//           # # # # # # #   
//           # # # # # # # # 
//                           
//           2 4 5 3 4 5 6 1 
//                           
//     Index 0 1 2 3 4 5 6 7 
//
//   5. Notice that, even if it equals. we should push in. the order is non decreasing not increasing. Because, consider about the left boundary, 3 xxx 3 4 5 , for 4 we need the second 3 as its boundary.  for 3 xxx 3 xxx 2, even if the second 3 is not its boundary, it doesn't matter, the first 3 will replace the result from second 3 later.   
//
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include"util.hpp"
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {

            int len = height.size();

            if(0 == len)
                return 0;

            stack<int> sta;
            sta.push(0);

            int maxArea = -1;

            height.push_back(-1);
            len++;

            for(int i = 1; i != len; ++i)
            {
                
                while( !sta.empty() && height[sta.top()] > height[i] )
                {
                /*
                        stack<int> tmp = sta;
                        while(!tmp.empty())
                        {
                            cout << tmp.top() << " "; 
                            tmp.pop();
                        }
                        cout << endl;
                */
     //           cout << stackToString(sta) << endl; 
                        int index = sta.top();
                        sta.pop();
                        maxArea = max( maxArea, height[index]*(i-(sta.empty()?-1:sta.top())-1) ); 
    //                    cout << maxArea << endl;
                        //cout <<  height[index]*(i-(sta.empty()?-1:sta.top())-1) << endl;
                }
                if(sta.empty() || height[sta.top()] <= height[i] )
                    sta.push(i);

//                       #   
//               #     # #   
//             # #   # # #   
//             # # # # # #   
//           # # # # # # #   
//           # # # # # # # # 
//                           
//           2 4 5 3 4 5 6 1 
//                           
//     Index 0 1 2 3 4 5 6 7 
            }
                        //cout << maxArea << endl;
            //maxArea = max( maxArea, height[sta.top()]*len); 
                        //cout << maxArea << endl;
            return maxArea;
        }
};

int main()
{
    Solution S;
    vector<int> a = {3,4,5,3,4,5,6,3};
    //vector<int> a = {2,1,5,6,2,3};
    //vector<int> a = {0, 1, 0, 1};
    cout << S.largestRectangleArea(a);
    return 0;
}
