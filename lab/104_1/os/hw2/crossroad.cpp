#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

int num[4]; //N E S W
int need[4][2] = {{0, 2},{1, 0},{3, 1},{2, 3}};
char trans[4] = {'N', 'E', 'S', 'W'};
int direction_status[4];
bool key_status[4];
bool deadlock;
int counter;
sem_t timer;
sem_t dir[4];
sem_t key;

void get_key(int dir, int status){
    int key_number = need[dir][status];
    if(key_status[key_number] == 0){
        direction_status[dir]++;
        key_status[key_number] = 1;
    } else {
        return;
    }
}
void release_key(int dir, int status){
    int key_number = need[dir][status];
    key_status[key_number] = 0;
}
void* go(void* _dir){
    int direction = *((int*)_dir);
    int cnt = 0;
    while(num[direction]){
        sem_wait(&dir[direction]);
        sem_wait(&key);
        if(direction_status[direction] == 0){
            get_key(direction, direction_status[direction]);
        } else if(direction_status[direction] == 1) {
            if(deadlock && direction == 0){
                release_key(direction, 0);
                direction_status[direction] = 0;
            } else {
                get_key(direction, direction_status[direction]);
            }
        } else if(direction_status[direction] == 2) {
            cout << trans[direction] << ' ' << cnt << " leaves at " << counter << endl;
            direction_status[direction]++;
            ++cnt;
        } else {
            release_key(direction, 0);
            release_key(direction, 1);
            direction_status[direction] = 0;
            num[direction]--;
        }
        sem_post(&key);
        sem_post(&timer);
    }
    return (void*)0;
}

int remain(){
    int re = 0;
    for(int i = 0 ; i < 4 ; i++)
        if(num[i]) re++;
    return re;
}

void* Timer(void*){
    int re = remain();
    while(1){
        for(int i = 0 ; i < re ; i++)
            sem_wait(&timer);
        counter++;
        int status1 = 0;
        for(int i = 0 ; i < 4 ; i++)
            if(direction_status[i] == 1)
                status1++;
        deadlock = status1 == 4;
        if(deadlock){
            cout << "Deadlock: " << counter << endl;
        }
        re = remain();
        if(re == 0)
            return (void*)0;
        for(int i = 0 ; i < 4 ; i++)
            if(num[i]){
                sem_post(&dir[i]);
            }
    }
}

int main(int argc, char* argv[]){
    for(int i = 0 ; i < 4 ; i++)
        num[i] = atoi(argv[i+1]);
    /* init semaphore */
    sem_init(&timer, 0, remain());
    sem_init(&key, 0, 1);
    for(int i = 0 ; i < 4 ; i++)
        sem_init(&dir[i], 0, 0);
    /* create thread */
    pthread_t timer;
    pthread_t go_thread[4];
    int arg[4];
    pthread_create(&timer, NULL, Timer, 0);
    for(int i = 0 ; i < 4 ; i++){
        arg[i] = i;
        pthread_create(&go_thread[i], NULL, go, &arg[i]);
    }
    /* join thread */
    for(int i = 0 ; i < 4 ; i++)
        pthread_join(go_thread[i], NULL);
    pthread_join(timer, NULL);

    
    return 0;
}
