//g++ -c DynArray.cpp && g++ DynArray.o -o DynArray.out && rm DynArray.o

#include<iostream>
using namespace std;

int main ()
{

    // dynamic array using pointers


    int size;
    cout<< "enter the size of my array = ";
    cin>>size; 

    int *arr = new int[size]; // allocates memory here

    // the arr stores the the first address of my array of size [size] in int format

    cout<<arr<<endl<<endl;

    for(int i=0;i<size;i++)
    {
        cout<<"enter the value of array["<<i<<"] = ";
        cin>> *(arr+i);  
    }

     for(int i=0;i<size;i++)
    {
        cout<<"the value of array["<<i<<"] = "<<*(arr+i)<<endl;
    
    }

    // since we allocated memory dynamically we need to deallocate - good practice

    delete[]arr; //delete keyword deallocates memory of that arr
    arr = NULL; // good practice to null the ptr so after deallocation it doest point to anywhere.

    return 0;
}