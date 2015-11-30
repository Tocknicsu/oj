#include <bits/stdc++.h>
#include <pthread.h>
int THREAD_NUM;
int TOTAL_POINTS;
using namespace std;

pthread_spinlock_t spinlock;

int circle, total;

void* ThreadRunner(void* arg){
    int num = *(int*) arg;
	unsigned int seed = rand();
	int _num;
	if(num == THREAD_NUM - 1){
		_num = TOTAL_POINTS - (THREAD_NUM - 1) * (TOTAL_POINTS / THREAD_NUM);
	} else {
		_num = TOTAL_POINTS / THREAD_NUM;
	}
    for(int k = 0 ; k < _num ; k++){
		double x = double(rand_r(&seed)) / RAND_MAX;
		double y = double(rand_r(&seed)) / RAND_MAX;
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
    THREAD_NUM = 16;
    TOTAL_POINTS = 100000000;
    if(argc > 1){
    //    THREAD_NUM = atoi(argv[1]);
        TOTAL_POINTS = atoi(argv[1]);
    }
    /*
    if(argc > 2){
        TOTAL_POINTS = atoi(argv[1]);
    }
    */
    srand(time(NULL));
    pthread_t tid[THREAD_NUM];
    pthread_spin_init(&spinlock, 0);
    int arg[THREAD_NUM];
    for(int i = 0 ; i < THREAD_NUM ; i++){
        arg[i] = i;
        pthread_create(&tid[i], NULL, ThreadRunner, (void*)&arg[i]);
    }
    for(int i = 0 ; i < THREAD_NUM ; i++)
        pthread_join(tid[i], NULL);
    cout << "pi estimate =" << fixed << setprecision(6) << 4 * float(circle) / float(total) << endl;
    return 0;
}
