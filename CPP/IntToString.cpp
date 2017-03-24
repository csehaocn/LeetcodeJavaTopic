#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    int x = 1234;
    ostringstream oss;
    oss << x;
    string s = oss.str();
    std::reverse('-'==*s.begin()?s.begin()+1:s.begin(), s.end());
    istringstream iss(s);
    int result;
    iss >> result;
    return result;
}

