#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;
int counter = 0;

void* threadFun(void* arg)
{
    printf("Inside Thread function \n");

    pthread_mutex_lock(&lock);
    printf("Got the mutex Counter now: %d \n", counter);
    counter += 20;
    pthread_mutex_unlock(&lock);

    return NULL;
}


int main()
{
    pthread_t tid[2];
    

    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed \n");
    }

    int i = 0;

    while (i < 2)
    {
        int error = pthread_create(&tid[i], NULL, &threadFun, NULL);
        if (error != 0)
        {
            printf("Thread Creation failed error code %d \n", error);
        }
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
