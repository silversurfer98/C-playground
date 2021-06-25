//g++ -c func-with-multiple-returns.cpp && g++ func-with-multiple-returns.o -o func-with-multiple-returns.out && rm func-with-multiple-returns.o
#include<iostream>
using namespace std;

void addsub (int a, int b, int* ad, int *su)
{
    // this is a example of pass by refernece
    // remember * means dereference and points to that variable itself
    *ad = a+b;
    *su = a-b;
}
int main()
{
    cout<<"add and sub 2 numbers using same function"<<endl;
    int a, b, add = 0, sub = 0;
    cin>>a>>b;
    addsub(a,b,&add,&sub);

    // im passing the address directly so no need returns !! power of pointers.......
    cout<<"add = "<<add<<endl<<"sub = "<<sub<<endl;
    cout<<"hurray !!";
    

    return 0;
}