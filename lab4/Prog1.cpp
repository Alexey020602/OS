#include<pthread.h>
#include<iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(int c, char** A)
{
    int N=5;
    cout<<"Prog1";
    cout<<A<<endl;
    cout<<(int**)A<<endl;
    cout<<*(int**)A<<endl;
    cout<<**(int**)A<<endl;
    cout<<"Prog1";
    int*B=(int*)A[0];
    cout<<B<<endl;
    cout<<*B<<endl;
    //int* A=new int[N];
    // for(int i=0; i<N; i++)
    // {
    //     cin>>A[i];
    // }
    // for(int i=0;i<N; i++)
    // {
    //     cout<<B[i]<<" "<<flush;
    // }
}