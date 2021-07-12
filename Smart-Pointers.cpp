#include<iostream>
using namespace std;
#define dline cout<<endl<<endl
#define sline cout<<endl

// needed to write smart pointer
#include<memory>

// there are 3 pointer types
// 1. is unique pointer


class demo
{
    public:
        demo ()
        {
            cout<<endl<<"constructor is called !!!"<<endl;
        }
        ~demo ()
        {
            cout<<endl<<"destructor is called !!!"<<endl;
        }
        friend void unique_pointers();
        friend void shared_pointers();
        friend void weak_pointers();

};

void unique_pointers()
{
    sline;
    // executuin of 1. is unique pointers

    int a;
    cin>>a;

    unique_ptr<int>uptr = make_unique<int>(a);
    cout<<"before auto deallocation : "<<uptr.get()<<endl<<*uptr<<endl;

    unique_ptr<int>uptr2 = move(uptr);
    // once move operation called the previous ptr or the owner will be null.....

    cout<<uptr2.get()<<endl<<*uptr2<<endl;
    
    cout<<"after auto deallocation : "<<uptr.get()<<endl<<*uptr<<endl;

    
    demo wtf;
    
    {
        unique_ptr<demo>uptr1 = make_unique<demo>(wtf);
        // end of the scope the unique ptr will be destroyed as we cal see destructor has been called
    }
    

}

void shared_pointers()
{
    // executuin of 2. is shared pointers
    sline;
    int a;
    cin>>a;

    shared_ptr<int>shptr1 = make_shared<int>(a);
    cout<<shptr1.get()<<endl<<*shptr1<<endl;



}

int main ()
{
    unique_pointers();
    return 0;
}
