#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;




void* proc1(void* flag)
{
    cout<<"thread 1 start working"<<endl;
    int *flag1=(int*)flag;
    while ((*flag1) ==0)
    {
        cout << "1"<<flush ;
        sleep(1);
    }
    cout<<"thread 1 end working"<<endl;
    return (void*)new int(3);

}



void* proc2(void* flag)
{
     cout<<"thread 2 start working"<<endl;
    int *flag2=(int*)flag;
    while ((*flag2) ==0)
    {
        cout << "2"<<flush;
        sleep(1);
    }
    cout<<"thread 2 end working"<<endl;
    return (void*)new int(4);
}



int main()
{
    cout<<"programm start working"<<endl;
    int flag1= 0;
    int flag2= 0;

    int* test1;
    int* test2;

    pthread_t id1;
    pthread_t id2;

    pthread_create(&id1, NULL, proc1, &flag1);
    pthread_create(&id2, NULL, proc2, &flag2);

    getchar();
    flag1 = 1;

    flag2 = 1;

    pthread_join(id1, (void**)&test1);
    pthread_join(id2, (void**)&test2);
    cout<<(*test1)<<(*test2);
    delete test1;
    cout<<"test1 deleted"<<endl;
    delete test2;
    cout<<"test2 deleted"<<endl;
    cout<<"programm end working"<<endl;
    return 0;
}