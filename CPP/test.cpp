#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <set>
#include <memory>

using namespace std;

/*********************1*************************/

const int N = 100;

typedef int (*PARA) [N];

PARA foo(int *p){
    return NULL;
}

/***********************************************/

int main(){

cout << "In Main" << endl;

/*********************1*************************/

int (*(*func)(int *p))[N];

func = foo; 


/***********************************************/

int ((*func2)(void))[N];

return 0;

}
