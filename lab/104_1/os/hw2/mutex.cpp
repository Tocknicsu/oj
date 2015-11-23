#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
pthread_mutex_t m_mutex;
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
        pthread_mutex_lock(&m_mutex);
        x.Increment();
        pthread_mutex_unlock(&m_mutex);
    }
}

int main(int argc, char* argv[]){
    int thread_num = 3;
    if(argc > 1)
        thread_num = atoi(argv[1]);
    pthread_t tid[thread_num];
    for(int i = 0 ; i < thread_num ; i++)
        pthread_create(&tid[i], NULL, ThreadRunner, 0);
    for(int i = 0 ; i < thread_num ; i++)
        pthread_join(tid[i], NULL);
    x.Print();
    return 0;
}
