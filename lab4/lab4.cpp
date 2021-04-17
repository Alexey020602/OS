#include<pthread.h>
#include<iostream>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    int* A= new int[5];
    for(int i=0; i<5; i++)
    {
        /*cin>>*/A[i]=i;
    }
    cout<<A<<endl;
    
    cout<<(char*)A<<endl;
    execlp("/mnt/c/Users/Fedor_kv2an24/source/repos/Учеба/ОС/lab4/Prog1",(char*)A, NULL);
}