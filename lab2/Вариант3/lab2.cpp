#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;
struct parameters
{
    int flag;
    pthread_mutex_t *mut;
};
void *proc1(void *params)
{
    cout << "thread 1 start working" << endl;
    parameters *param = (parameters *)params;
    timespec tp;
    while (param->flag == 0)
    {

        clock_gettime(CLOCK_REALTIME, &tp);
        tp.tv_sec += 5;
        if (pthread_mutex_timedlock(param->mut, &tp) == ETIMEDOUT)
        {
            continue;
        }
        for (int i = 0; i < 5; i++)
        {
            cout << "1" << flush;
            sleep(1);
        }
        pthread_mutex_unlock(param->mut);
        sleep(1);
    }
    cout << "thread 1 end working" << endl;
    return (void *)new int(3);
}

void *proc2(void *params)
{
    cout << "thread 2 start working" << endl;
    parameters *param = (parameters *)params;
    timespec tp;
    while (param->flag == 0)
    {
        clock_gettime(CLOCK_REALTIME, &tp);
        tp.tv_sec += 5;
        if (pthread_mutex_timedlock(param->mut, &tp) == ETIMEDOUT)
        {
            continue;
        }
        for (int i = 0; i < 5; i++)
        {
            cout << "2" << flush;
            sleep(1);
        }
        pthread_mutex_unlock(param->mut);
        sleep(1);
    }
    cout << "thread 2 end working" << endl;
    return (void *)new int(4);
}

int main()
{
    cout << "programm 3 start working" << endl;
    int flag1 = 0;
    int flag2 = 0;

    int *test1;
    int *test2;

    pthread_t id1;
    pthread_t id2;
    pthread_mutex_t mut;
    pthread_mutex_init(&mut, NULL);
    parameters param1 = {0, &mut};
    parameters param2 = {0, &mut};
    pthread_create(&id1, NULL, proc1, (void *)&param1);
    pthread_create(&id2, NULL, proc2, (void *)&param2);

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
    pthread_mutex_destroy(&mut);
    cout << "mut deleted" << endl;
    cout << "programm end working" << endl;
    return 0;
}