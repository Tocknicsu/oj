#include <iostream>
#include <cstdlib>
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
            cout << value << endl;
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
int main(int argc, char* argv[]){
    int thread_num = 3;
    if(argc > 1)
        thread_num = atoi(argv[1]);
    sem_init(&m_mutex, 0, 1);
    pthread_t tid[thread_num];
    for(int i = 0 ; i < thread_num ; i++)
        pthread_create(&tid[i], NULL, ThreadRunner, 0);
    for(int i = 0 ; i < thread_num ; i++)
        pthread_join(tid[i], NULL);
    sem_destroy(&m_mutex);
    x.Print();
    return 0;
}
