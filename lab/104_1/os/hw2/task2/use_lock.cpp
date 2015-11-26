#include <bits/stdc++.h>
#include <pthread.h>
int THREAD_NUM;
int TOTAL_POINTS;
using namespace std;

pthread_spinlock_t spinlock;

int circle, total;

void* ThreadRunner(void*){
    unsigned int seed = rand();
    for(int i = 0 ; i < TOTAL_POINTS ; i++){
        seed = rand_r(&seed);
        float x = float(seed) / RAND_MAX;
        seed = rand_r(&seed);
        float y = float(seed) / RAND_MAX;
        pthread_spin_lock(&spinlock);
        total += 1;
        pthread_spin_unlock(&spinlock);
        if(x * x + y * y <= 1){
            pthread_spin_lock(&spinlock);
            circle += 1;
            pthread_spin_unlock(&spinlock);
        }
    }
}

int main(int argc, char* argv[]){
    THREAD_NUM = atoi(argv[1]);
    TOTAL_POINTS = atoi(argv[2]);
    pthread_t tid[THREAD_NUM];
    pthread_spin_init(&spinlock, 0);
    for(int i = 0 ; i < THREAD_NUM ; i++){
        pthread_create(&tid[i], NULL, ThreadRunner, NULL);
    }
    for(int i = 0 ; i < THREAD_NUM ; i++)
        pthread_join(tid[i], NULL);
    pthread_spin_destroy(&spinlock);
    cout << 4 * float(circle) / float(total) << endl;
    return 0;
}
