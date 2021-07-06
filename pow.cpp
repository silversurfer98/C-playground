//g++ -c pow.cpp && g++ pow.o -o pow.out && rm pow.o

#include<iostream>
#include<stdlib.h>
using namespace std;

float pow(float number, float exp)
{
    if(exp==0)
        return 1;
    else if(exp==1)
        return number;
    else
    {
        float ans = 1;
        for(int i=1;i<=exp;i++)
            ans = ans*number;
        return ans;
    }
}

int main ()
{
    float a,b;
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
}