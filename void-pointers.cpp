//g++ -c void-pointers.cpp && g++ void-pointers.o -o void-pointers.out && rm void-pointers.o

#include<iostream>
using namespace std;


// void pointers can store address of any datatype even struct
// but we need to typecast it before using it
// void pointers can cause logical errors rather than throwing compile time error
/* because we can type cast void ptr to anything so if i typecast void to int 
    but ptr passed to func is char it wont raise a error rather it prints wrong value */

void print(void *ptr, char parameter)
{
    // i used char parameter to check what kinf of datatype im receiving

    switch (parameter)
    {
        case 'i':
            // handles int datatype, typecast void ptr to int ptr and derefernce it and print it
            cout<<*((int*)ptr)<<endl;
            break;
         case 'c':
            // handles char datatype, typecast void ptr to char ptr and derefernce it and print it
            cout<<*((char*)ptr)<<endl;
            break;
    }
}

int main ()
{
    int n = 5;
    char c = 'a';
    print(&n,'i');
    print(&c,'c');

    return 0;
}
