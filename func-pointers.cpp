//g++ -c func-pointers.cpp && g++ func-pointers.o -o func-pointers.out && rm func-pointers.o


/* in this file we consolidate all we learned so far
# dynamic array - allocation and deallocation
# using function pass by refernce
## and now using function pointers */

#include<iostream>
using namespace std;

bool checkgreater(int a, int b)
{
    return a<b;
}

bool checklesser(int a, int b)
{
    return a>b;
}

void swap (int *a, int *b)
{
    int t;
    *a = t;
    *a = *b;
    *b = t;
}

void sort(int *a, int size, bool (*check)(int,int))
{
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(check(a[i],a[j]))
                swap (&a[i],&a[j]);
          
        }

    }
}

// using function pointer we can pass function to a function, which make more code obsolete.

// void sortacending(int *a, int size)
// {
    
//     for(int i=0;i<size;i++)
//     {
//         for(int j=0;j<size;j++)
//         {
//             if(checkgreater(a[i],a[j]))
//                 swap (&a[i],&a[j]);
          
//         }

//     }
// }

// void sortdescending(int *a, int size)
// {
    
//     for(int i=0;i<size;i++)
//     {
//         for(int j=0;j<size;j++)
//         {
//             if(checklesser(a[i],a[j]))
//                 swap (&a[i],&a[j]);
          
//         }

//     }
// }

void print(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<"The ["<<i<<"] element : "<<arr[i]<<endl;
    }
    cout<<endl;
}


int main()
{
    int size;
    cout<<"enter the size of the array : ";
    cin>>size;
    // dynamic array xD
    int *array = new int[size];
    for(int i=0;i<size;i++)
    {
        cout<<"enter the ["<<i<<"] element : ";
        cin>>array[i];
    }

    // create a function pointer
    bool (*funcptr)(int,int);

    print(array,size);

    cout<<"1. Acsending order"<<endl<<"2. Decending order"<<endl<<"enter your choice : ";
    int c;
    cin>>c;
    cout<<endl;
    switch(c)
    {
        case 1 : 
            funcptr = checkgreater;
            sort(array,size,funcptr); 
            break;
        case 2 : 
            funcptr = checklesser;
            sort(array,size,funcptr); 
            break;
    }

    print(array,size);
    
    cout<<"to clear memory press 1 :";
    int ch;
    cin>>ch;
    if(ch==1)
    {
    cout<<"clearing the allocated memory ";
    cout<<"the present address of array : "<<array<<" now deleteing ......"<<endl;
    delete[] array;
    array = nullptr;
    cout<<"now deleted see : "<<array<<endl;
    }
    else
    {
        cout<<"array not deleted, it can be accessed from this memory : " <<array<<endl;
    }



    // when ole reached program is completed - returns 0;
    cout<<"**************__ole__**************"<<endl;
    return 0;

    // this whole implementation can be done using vectors - true dynamic arrays
}