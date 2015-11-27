
#time ./mutex                2
#time ./sem                  2
#time ./spinlock             2
#time ./homemade_spinlock    2

#time ./mutex                4
#time ./sem                  4
#time ./spinlock             4
#time ./homemade_spinlock    4

#time ./mutex                8
#time ./sem                  8
#time ./spinlock             8
#time ./homemade_spinlock    8

#time ./mutex                16
#time ./sem                  16
#time ./spinlock             16
#time ./homemade_spinlock    16

time ./pi_free 1 100000000
time ./pi_lock 1 100000000

time ./pi_free 16 100000000
time ./pi_lock 16 100000000
