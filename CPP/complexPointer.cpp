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

void t1(){
    int (*(*func)(int *p))[N];

    func = foo; 
    return; 

// int ((*func2)(void))[N];
// compile : 'func2' declared as function returning an array


}


/*********************2*************************/

typedef int fun(int,int);
fun *f;

int foo2(int i, int j){
    return 0;
}

void t2(){

    fun *f2;
    fun f3;
    // what does fun f3 declared.
    f2 = foo2;
    // xxx f3 = *f2;
    // Notice that f3 can not be used, the name of function is a call stack address, but it is declared as a constant in c++. We can't change the value of f3 and point f3 to any other value.
    // 
}

/*********************3*************************/

int foo3(int i, int j){

    return 0;
}

void t3(){
    if(foo3 == &foo3) 
    {
        cout << "foo3 == &foo3" << endl;
    }
    return;
}
/*********************4*************************/

typedef int ret4(int* i, int j);
typedef void (*ret4p(int* i, int j));

ret4* foo4(int i){
    return NULL;
}

ret4p* foo4p(int i){
    return NULL;
}

// Please notice the difference below
//
// ff is a function, not a function pointer, therefore
// int (*ff(int)) (int* i, int j); is a function declaration not a function pointer declaration
int (*ff(int)) (int* i, int j){
    return 0;
}
int (*ff3 (int i)) (int){
    return NULL;
}

void t4(){
    // fp is a function pointer which can piont to ff
    // Notice how the ( ) are used here.
    int (*(*fp)(int)) (int* i, int j);

    // usually the declaration of function pointer has to have a ( ) around, or the return type like int will eat the * symbol. 
    int (*fp2) (int);

    // while the second situation is when function return a function pointer. which makes it a little bit different  
    //  Like ff3 above, this is a function with para int i, with return type function pointer int (int); 

    fp = ff;
    return ;
}


/*********************i*************************/
void ti(){
    return;
}

int main(){

    cout << "In Main" << endl;

    t3();

    return 0;

}
