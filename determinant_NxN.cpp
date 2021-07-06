//g++ -c determinant_NxN.cpp && g++ determinant_NxN.o -o determinant_NxN.out && rm determinant_NxN.o


#include<iostream>
#include<stdlib.h>
using namespace std;

int i,j;
float ans = 0, t = 0, omale = 0;

float **createArray(int n)
{
    float **array = new float*[n];
    for(i=0;i<n;i++)
        array[i] = new float[n];
    //cout<<"im inside the function so address is :"<<array<<endl;;
    return array;
}

void DelArray(float **addressOfTable, int n)
{
    //cout<<"im called"<<endl;
    for(i=0;i<n;i++)
    {
        //cout<<"im entering for "<<i<<endl;
        delete[] addressOfTable[i];
        //free(addressOfTable[i]);
    }
    
    //free(addressOfTable);
    delete[] addressOfTable;
    //addressOfTable = NULL;
    //cout<<"im executed"<<endl;

}

void printArray(float **table, int n)
{
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<endl;
        for(j=0;j<n;j++)
            cout<<table[i][j]<<"  ";
    }
    cout<<endl;

}

float det22(float **array,int n)
{
    if(n==2)
        return (array[0][0]*array[1][1] - array[0][1]*array[1][0]);
    else
    {
        cout<<"************************"<<endl;
        cout<<"u fuckwit dont call me ....."<<endl;
        printArray(array,n);
        cout<<"************************"<<endl;

    }
}

void subMatrixMaker(float **table, int *n, int No_of_Rows_toFindSub)
{
    // my logic starts here .....
    t=0;
    int f=0, l=0;
    if(No_of_Rows_toFindSub<=*n)
    {
    for(l=0;l<No_of_Rows_toFindSub;l++)
    {
    for(int k=0;k<*n;k++)
        {
            int a=0, b=0;
            //int nn = n-1;
            float **submatrix = createArray(*n-1);
            //cout<<"matrix is created"<<endl;
            for(i=0;i<*n;i++)
            {
                for(j=0;j<*n;j++)
                {
                    if(i!=l && j!=k)
                    {
                        //cout<<"here inside if index : "<<i<<j<<endl;
                        submatrix[a][b] = table[i][j];
                        //submatrix[a][b] = submatrix[a][b] * table[l][k];
                        //cout<<submatrix[a][b]<<endl;
                        b++;
                        if(b == *n-1)
                        {
                            f=1;
                            b=0;
                        }
                    }

                }
                if(f==1)
                    a++;
                f=0;
                //cout<<"index of submat : "<<a<<b<<endl;
            }
            cout<<"this is a sub matrix of : "<<table[l][k]<<endl;
            printArray(submatrix,*n-1);
            //cout<<"det of submat : "<<det22(submatrix,n-1)<<endl;
            cout<<endl;
        }

    
    }
    }
    *n--;
    
}


int main ()
{
    int n;
    cout<<"enter order of matrix : ";
    cin>>n;   
       
    float **table = createArray(n);

    cout<<"address in main func :"<< table<<endl;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>table[i][j];
  
    cout<<endl<<endl;

    cout<<"**********"<<table<<"***********"<<endl;
    printArray(table,n); 
    cout<<"*********************************"<<endl;

    //cout<<endl<<"********** omale : "<<detDriver(table,n)<<endl;
    subMatrixMaker(table,&n,1);
    cout<<endl<<"now N is :"<<n<<endl;



    DelArray(table,n);
    table = nullptr;
    
    return 0;
}
