#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t m_mutex;

class Counter{
    int value;
    public:
        Counter() : value(0) {}
        void Increment(){
            value++;
        }
        void Print(){
            cout << value;
        }
};


Counter x;

void* ThreadRunner(void*){
    for(int k = 0 ; k < 100000000 ; k++){
        sem_wait(&m_mutex);
        x.Increment();
        sem_post(&m_mutex);
    }
}

int main(){
    sem_init(&m_mutex, 0, 1);
    pthread_t tid[3];
    for(int i = 0 ; i < 3 ; i++)
        pthread_create(&tid[i], NULL, ThreadRunner, 0);
    for(int i = 0 ; i < 3 ; i++)
        pthread_join(tid[i], NULL);
    sem_destroy(&m_mutex);
    x.Print();
    return 0;
}
