//g++ -c determinant_NxN.cpp && g++ determinant_NxN.o -o determinant_NxN.out && rm determinant_NxN.o


#include<iostream>
using namespace std;

float **createArray(int n)
{
    float **array = new float*[n];
    for(int i=0;i<n;i++)
        array[i] = new float[n];
    //cout<<"im inside the function so address is :"<<array<<endl;;
    return array;
}

void DelArray(float **addressOfTable, int n)
{
    //cout<<"im called"<<endl;
    for(int i=0;i<n;i++)
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
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        for(int j=0;j<n;j++)
            cout<<table[i][j]<<"  ";
    }

}

float det22(float **array,int n)
{
    if(n==2)
        return (array[0][0]*array[1][1] - array[0][1]*array[1][0]);
    else
        return 0;
}



int main ()
{
    int n;
    cout<<"enter order of matrix : ";
    cin>>n;   
       
    float **table = createArray(n);

    cout<<"address in main func :"<< table<<endl;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>table[i][j];
  
    cout<<endl<<endl;

    cout<<"**********"<<table<<"***********"<<endl;
    printArray(table,n); 
    cout<<endl;


// my logic starts here .....
float ans = 0,t =0;
int f=0, l=0;
for(int k=0;k<n;k++)
{
    int a=0, b=0;
    int nn = n-1;
    float **submatrix = createArray(nn);
    cout<<"matrix is created"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=l && j!=k)
            {
                //cout<<"here inside if index : "<<i<<j<<endl;
                submatrix[a][b] = table[i][j];
                //submatrix[a][b] = submatrix[a][b] * table[l][k];
                //cout<<submatrix[a][b]<<endl;
                b++;
                if(b == n-1)
                {
                    f=1;
                    b=0;
                }
            }

        }
        if(f==1)
            a++;
        f=0;
        cout<<"index of submat : "<<a<<b<<endl;
    }
    printArray(submatrix,nn);
    cout<<"det of submat : "<<det22(submatrix,nn)<<endl;
    cout<<endl;
    if(n-1 == 2)
    {
        t = (table[l][k]*det22(submatrix,nn));
        if(k%2!=0)
            t = t * -1;
        ans = ans + t ;

    }
    

    DelArray(submatrix,nn);
    submatrix = nullptr;
}

cout<<endl<<"********** omale : "<<ans<<endl;


    DelArray(table,n);
    table = nullptr;
    
    return 0;
}
