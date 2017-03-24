#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

class Solution {

    public:
        void generateParenthesisHeplper(int a, int b, vector<string>& vec){
            if(0==a && 0 == b)
                return;
            if(a == 0){
                for(vector<string>::iterator it = vec.begin(); it!=vec.end();it++){
                    it->append(")");
                }
                generateParenthesisHeplper(a, b-1, vec);
            }else if(a==b){
                for(vector<string>::iterator it = vec.begin(); it!=vec.end();it++){
                    it->append("(");
                }
                generateParenthesisHeplper(a-1, b, vec);
            }else{
                vector<string> temp(vec);
                for(vector<string>::iterator it = vec.begin(); it!=vec.end();it++){
                    it->append("(");
                }
                generateParenthesisHeplper(a-1, b, vec);
                
                for(vector<string>::iterator it = temp.begin(); it!=temp.end();it++){
                    it->append(")");
                }
                generateParenthesisHeplper(a, b-1, temp);
                vec.insert(vec.begin(),temp.begin(),temp.end());
            }
            return;
        }
        vector<string> generateParenthesis(int n) {
            vector<string> vec;
            vec.push_back("");
            generateParenthesisHeplper(n, n, vec);
            return vec;
        }
};
int main(){
    Solution s = Solution();
    vector<string> v= s.generateParenthesis(2); 
    for(auto it = v.begin(); it!=v.end(); it++){
        cout<<*it;
    }
    return 0;
}
