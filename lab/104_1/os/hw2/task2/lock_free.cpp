#include <bits/stdc++.h>
#include <pthread.h>
int THREAD_NUM;
int TOTAL_POINTS;
using namespace std;

pthread_spinlock_t spinlock;

class Counter{
    int circle, total;
    public:
    unsigned seed;
        Counter() : circle(0), total(0) {}
        void go(){
            double x = double(rand_r(&seed)) / RAND_MAX;
            double y = double(rand_r(&seed)) / RAND_MAX;
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


Counter x[128];

void* ThreadRunner(void* arg){
    int num = *(int*) arg;
    x[num].seed = rand();
    int _num = TOTAL_POINTS / THREAD_NUM;
    for(int k = 0 ; k < _num ; k++){
        x[num].go();
    }
}

int main(int argc, char* argv[]){
    THREAD_NUM = atoi(argv[1]);
    TOTAL_POINTS = atoi(argv[2]);
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
