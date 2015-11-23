all: mutex.cpp sem.cpp spinlock.cpp homemade_spinlock.cpp pi_lock.c pi_free.c crossroad.c
	g++ mutex.cpp -lpthread -o mutex
	g++ sem.cpp -lpthread -o sem
	g++ spinlock.cpp -lpthread -o spinlock
	g++ homemade_spinlock.cpp -lpthread -o homemade_spinlock
	gcc pi_lock.c -lpthread -o pi_lock
	gcc pi_free.c -lpthread -o pi_free
	gcc crossroad.c -lpthread -o crossroad
clean:
	rm -f mutex
	rm -f sem
	rm -f spinlock
	rm -f homemade_spinlock
	rm -f pi_lock
	rm -f pi_free
	rm -f crossroad
