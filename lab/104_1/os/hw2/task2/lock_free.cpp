#include <bits/stdc++.h>
#include <pthread.h>
#define THREAD_NUM 4
#define EACH_POINTS 1000000
using namespace std;

pthread_spinlock_t spinlock;

class Counter{
    int circle, total;
    public:
        Counter() : circle(0), total(0) {}
        void go(){
            float x = float(rand()) / RAND_MAX;
            float y = float(rand()) / RAND_MAX;
            total += 1;
            if(x * x + y * y <= 1)
                circle += 1;
        }
        void print(){
            cout << circle << '/' << total << endl;
        }
        int get_total() { return total; }
        int get_circle() { return circle; }
};


Counter x[THREAD_NUM];

void* ThreadRunner(void* arg){
    int* num = (int*) arg;
    for(int k = 0 ; k < EACH_POINTS ; k++){
        x[*num].go();
    }
}

int main(){
    pthread_t tid[THREAD_NUM];
    int arg[THREAD_NUM];
    pthread_spin_init(&spinlock, 0);
    for(int i = 0 ; i < THREAD_NUM ; i++){
        arg[i] = i;
        pthread_create(&tid[i], NULL, ThreadRunner, (void*)&arg[i]);
    }
    for(int i = 0 ; i < THREAD_NUM ; i++)
        pthread_join(tid[i], NULL);
    pthread_spin_destroy(&spinlock);
    int total = 0, circle = 0;
    for(int i = 0 ; i < THREAD_NUM ; i++)
        total += x[i].get_total(), circle += x[i].get_circle();
    cout << 4 * float(circle) / float(total) << endl;
    return 0;
}
