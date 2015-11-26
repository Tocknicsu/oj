#include <bits/stdc++.h>
#include <pthread.h>
int THREAD_NUM;
int TOTAL_POINTS;
using namespace std;

int circle[128];
int total[128];

void* ThreadRunner(void* arg){
    int num = *(int*) arg;
	unsigned int seed = rand();
	int _num;
	if(num == THREAD_NUM - 1){
		_num = TOTAL_POINTS - (THREAD_NUM - 1) * (TOTAL_POINTS / THREAD_NUM);
	} else {
		_num = TOTAL_POINTS / THREAD_NUM;
	}
	int local_total = 0, local_circle = 0;
    for(int k = 0 ; k < _num ; k++){
		double x = double(rand_r(&seed)) / RAND_MAX;
		double y = double(rand_r(&seed)) / RAND_MAX;
		local_total += 1;
		if(x * x + y * y <= 1)
			local_circle += 1;
    }
	circle[num] = local_circle;
	total[num] = local_total;
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
    int sum_total = 0, sum_circle = 0;
    for(int i = 0 ; i < THREAD_NUM ; i++)
		sum_total += total[i], sum_circle += circle[i];
    cout << sum_circle << ' ' << sum_total << endl;
    cout << 4 * float(sum_circle) / float(sum_total) << endl;
    return 0;
}
