#include <iostream>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#define TYPE_OF_BUFFER_DATA uid_t
using namespace std;
struct parameters
{
    int flag;
    int* filedes;
    uid_t* buffer;
};
void *proc1(void *params)
{
    cout << "thread 1 start working" << endl;
    parameters *param = (parameters *)params;
    
    while (param->flag == 0)
    {
        
        uid_t a=geteuid();
        param->buffer=&a;
        int check=write(param->filedes[1],param->buffer, sizeof(TYPE_OF_BUFFER_DATA));        
        if(check==EBADF) continue;
        if(check==EINVAL) continue;
        if(check==ENOSPC) continue;
        sleep(1);
    }
    cout << "thread 1 end working" << endl;
    return (void *)new int(3);
}

void *proc2(void *params)
{
    cout << "thread 2 start working" << endl;
    parameters *param = (parameters *)params;
    
    while (param->flag == 0)
    {
        //delete (uid_t*)param->buffer;
        int check=read(param->filedes[0],param->buffer, sizeof(TYPE_OF_BUFFER_DATA));   
        if(check==EINVAL) continue;
        if(check==EBADF) continue;
        passwd* a=getpwuid(*param->buffer);
        cout<<a->pw_dir<<endl<<a->pw_gecos<<endl<<a->pw_gid<<endl<<a->pw_name<<endl<<a->pw_passwd<<endl<<a->pw_shell<<endl<<a->pw_uid<<endl;
        sleep(1);
    }

    cout << "thread 2 end working" << endl;
    return (void *)new int(4);
}
int main()
{
    
    cout << "programm 2 start working" << endl;
    int flag1 = 0;
    int flag2 = 0;
    int *test1;
    int *test2;
    pthread_t id1;
    pthread_t id2;
    int* a=new int[2];
    pipe2(a,O_NONBLOCK);
    uid_t b;
    parameters param1={0, a, &b};
    parameters param2={0, a, &b};
    pthread_create(&id1, NULL, proc1,  (void*)&param1);
    pthread_create(&id2, NULL, proc2, (void*)&param2);

    getchar();
    param1.flag = 1;

    param2.flag = 1;

    pthread_join(id1, (void **)&test1);
    pthread_join(id2, (void **)&test2);
    cout << (*test1) << (*test2);
    delete test1;
    cout << "test1 deleted" << endl;
    delete test2;
    cout << "test2 deleted" << endl;
    close(a[0]);
    cout << "Pipe 1 destroyed" << endl;
    close(a[1]);
    cout << "Pipe 2 closed" << endl;
    cout << "programm end working" << endl;
    return 0;
}