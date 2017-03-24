// vector<vector<bool> > board_marker(lenRow, vector<bool>(lenCol, false) );
// put this initializer inside of the loop is not right, get the running time exceed always.
//
// The constructor usually is very slow, I think especially for large objects.
#include<iostream>
#include<vector>
#include<string>
#include"util.hpp"
using namespace std;

class Solution {
    
    bool DFS(vector<vector<char> > &board, vector<vector<bool> > &board_marker, int i, int j, string &word, int index)
    {
        if(index == word.size()) 
            return true;

            //cout << word << endl;
            //cout << index << " "<< i << j << endl;
        if(i >= board.size() || i < 0 || j >=board[0].size() || j <0)
        {
            //cout << "false" << endl;
            return false;
        }

        if( board_marker[i][j] )
            return false;

        /*
           ["ABCE"],
           ["SFCS"],
           ["ADEE"] 
         * */
        if(word[index] != board[i][j])
            return false;

        board_marker[i][j] = true;

        bool res = (DFS(board, board_marker, i-1, j, word, index+1)) || (DFS(board, board_marker, i+1, j, word, index+1)) || (DFS(board, board_marker, i, j-1, word, index+1)) || (DFS(board, board_marker, i, j+1, word, index+1));

        board_marker[i][j] = false;

        return res;    
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        
        int lenW = word.size();
        if(0 == lenW)
            return true;
        
        int lenRow = board.size();
        if( 0 == lenRow)
            return false;
        
        int lenCol = board[0].size();
        if( 0 == lenCol)
            return false;
        
        int wordIndex = 0;
        
        vector<vector<bool> > board_marker(lenRow, vector<bool>(lenCol, false) );
        for(int i = 0; i != lenRow; ++i)
        for(int j = 0; j != lenCol; ++j)
        {
    //        vector<vector<bool> > board_marker(lenRow, vector<bool>(lenCol, false) );
            bool u = DFS(board, board_marker, i, j, word, 0);
            if(u)
                return true;
        }
        
        return false;
            
    }
};

int main()
{
    /*
       ["ABCE"],
       ["SFCS"],
       ["ADEE"] 
     * */
    vector<vector<char> > input;
    string stmp = "ABCE";
    vector<char> vtmp(stmp.begin(), stmp.end());
    string stmp2 = "SFCS";
    vector<char> vtmp2(stmp2.begin(), stmp2.end());
    string stmp3 = "ADEE";
    vector<char> vtmp3(stmp3.begin(), stmp3.end());
    input.push_back(vtmp);
    input.push_back(vtmp2);
    input.push_back(vtmp3);
    pVector(input[0]);
    pVector(input[1]);
    pVector(input[2]);
    Solution S;
    cout << S.exist(input, "ABCESEEDASFC");
    return 0;
}
