#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
void homemade_spin_lock(volatile int* spinlock_addr){
    asm(
        "spin_lock: \n\t"
        "xorl %%ecx, %%ecx \n\t"
        "incl %%ecx \n\t"
        "spin_lock_retry: \n\t"
        "xorl %%eax, %%eax \n\t"
        "lock; cmpxchgl %%ecx, (%0) \n\t" "jnz spin_lock_retry \n\t"
        : : "r" (spinlock_addr) : "ecx", "eax" );
}
void homemade_spin_unlock(volatile int* spinlock_addr) {
    asm(
        "spin_unlock: \n\t" "movl $0, (%0) \n\t"
        : : "r" (spinlock_addr) : );
}
int spinlock;
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
        homemade_spin_lock(&spinlock);
        x.Increment();
        homemade_spin_unlock(&spinlock);
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
