#include <bits/stdc++.h>
#include <pthread.h>
#define THREAD_NUM 1
#define EACH_POINTS 100000000
using namespace std;

pthread_spinlock_t spinlock;

class Counter{
    int circle, total;
    public:
    unsigned seed;
        Counter() : circle(0), total(0) {}
        void go(){
            seed = rand_r(&seed);
            float x = float(seed) / RAND_MAX;
            seed = rand_r(&seed);
            float y = float(seed) / RAND_MAX;
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
    x[*num].seed = rand();
    int _num = EACH_POINTS / THREAD_NUM;
    for(int k = 0 ; k < _num ; k++){
        x[*num].go();
    }
}

int main(){
    srand(time(NULL));
    pthread_t tid[THREAD_NUM];
    int arg[THREAD_NUM];
    for(int i = 0 ; i < THREAD_NUM ; i++){
        arg[i] = i;
        pthread_create(&tid[i], NULL, ThreadRunner, (void*)&arg[i]);
    }
    for(int i = 0 ; i < THREAD_NUM ; i++)
        pthread_join(tid[i], NULL);
    int total = 0, circle = 0;
    for(int i = 0 ; i < THREAD_NUM ; i++)
        total += x[i].get_total(), circle += x[i].get_circle();
    cout << circle << ' ' << total << endl;
    cout << 4 * float(circle) / float(total) << endl;
    return 0;
}
