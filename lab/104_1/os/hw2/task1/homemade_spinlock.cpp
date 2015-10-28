#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
void homemade_spin_lock(int* spinlock_addr){
    asm(
        "spin_lock: \n\t"
        "xorl %%ecx, %%ecx \n\t"
        "incl %%ecx \n\t"
        "spin_lock_retry: \n\t"
        "xorl %%eax, %%eax \n\t"
        "lock; cmpxchgl %%ecx, (%0) \n\t" "jnz spin_lock_retry \n\t"
        : : "r" (spinlock_addr) : "ecx", "eax" );
}
void homemade_spin_unlock(int* spinlock_addr) {
    asm(
        "spin_unlock: \n\t" "movl $0, (%0) \n\t"
        : : "r" (spinlock_addr) : );
}

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
    for(int k = 0 ; k < 10000 ; k++){
        homemade_spin_lock(&spinlock);
        x.Increment();
        homemade_spin_unlock(&spinlock);
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