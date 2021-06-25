// for normal use g++ filename.cpp

// always compile using g++ -c FILENAME.cpp
// then 
// g++ FILENAME.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// then run ./sfml-app



#include<iostream>
#include<vector>
using namespace std;
int main ()
{
    vector<int> a;
    bool f=true;
    while(f)
    {
        int b;
        cin>>b;
        a.push_back(b);
        cout<<"do u want to stop"<<endl;
        int c;
        cin>>c;
        if(c==1)
        f=false;
    }

    cout<<"Printing all the values :"<<endl;
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<endl;

    return 0;
}