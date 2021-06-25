//g++ -c pointers.cpp && g++ pointers.o -o pointers.out && rm pointers.o

#include<iostream>
using namespace std;
int main()
{
    int n;
    //this will store the address of of n using the operator &, if u want to access the n via ptr derefernce the ptr again using * operator 
    int* ptr = &n;

    cin>>*ptr;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;

}