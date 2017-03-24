#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    using namespace std;
    string sentence = "And";
    std::string result;
    std::istringstream iss (sentence);
    std::ostringstream oss;
    string piece;
    while(iss){
        if(iss>>piece)
            oss<<piece;
        //piece.clear();
    }
    result = oss.str();
    cout<< result;
}
