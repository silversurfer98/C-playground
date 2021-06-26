//g++ -c 2D-arr-pointers.cpp && g++ 2D-arr-pointers.o -o 2D-arr-pointers.out && rm 2D-arr-pointers.o

//https://www.youtube.com/watch?v=mGl9LO-je3o

#include<iostream>
using namespace std;

int main ()
{
    int rows, cols;
    cout<<"rows : ";
    cin>>rows;
    cout<<"columns : ";
    cin>>cols;

    // 2d array is a pointer dynamic array of dynamic array.
    // consider a dynamic array in dyn memory and to access that we operate with a ptr that points to that first address
    // now we have several several such dyn arrays each has a ptr, so we arrange those ptrs in a dyn array and return the 
    // first address of the that ptr ptr dyn array to a pointer to a pointer.

    // lets implement this here

    // first i create pointer to a pointer 

    // now we create pointers of pointers array using this

    int **table = new int*[rows];

    // i use int*[rows] because it is a array of pointers and table points to that array of pointers

    //now using for loop create columns

    for(int i=0;i<rows;i++)
    {
        // normal dyn array is int *arr = new int[size];
        // but already table[i] is a pointer so no need to dereference it

        table[i] = new int[cols];

    }


    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cin>>table[i][j];


    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            cout<<table[i][j];


    //deallocation is important
    // concept of dyn programming is deallocation

    //first we need to deallocate cols as in reverse order as we created

    

    for(int i=0;i<rows;i++)
    {
        delete[] table[i];
    }
    
    delete[] table;
    table = NULL;
    return 0;
}
