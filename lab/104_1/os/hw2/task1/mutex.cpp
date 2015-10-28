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
            cout << value;
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

int main(){
    pthread_t tid[3];
    for(int i = 0 ; i < 3 ; i++)
        pthread_create(&tid[i], NULL, ThreadRunner, 0);
    for(int i = 0 ; i < 3 ; i++)
        pthread_join(tid[i], NULL);
    x.Print();
    return 0;
}
