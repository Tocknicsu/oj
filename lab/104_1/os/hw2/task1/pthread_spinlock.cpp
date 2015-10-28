#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

pthread_spinlock_t spinlock;

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
        pthread_spin_lock(&spinlock);
        x.Increment();
        pthread_spin_unlock(&spinlock);
    }
}

int main(){
    pthread_t tid[3];
    pthread_spin_init(&spinlock, 0);
    for(int i = 0 ; i < 3 ; i++)
        pthread_create(&tid[i], NULL, ThreadRunner, 0);
    for(int i = 0 ; i < 3 ; i++)
        pthread_join(tid[i], NULL);
    pthread_spin_destroy(&spinlock);
    x.Print();
    return 0;
}
