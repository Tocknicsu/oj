all: mutex.cpp sem.cpp spinlock.cpp homemade_spinlock.cpp pi_lock.cpp pi_free.cpp crossroad.cpp
	g++ mutex.cpp -lpthread -o mutex
	g++ sem.cpp -lpthread -o sem
	g++ spinlock.cpp -lpthread -o spinlock
	g++ homemade_spinlock.cpp -lpthread -o homemade_spinlock
	g++ pi_lock.cpp -lpthread -o pi_lock
	g++ pi_free.cpp -lpthread -o pi_free
	g++ crossroad.cpp -lpthread -o crossroad
clean:
	rm -f mutex
	rm -f sem
	rm -f spinlock
	rm -f homemade_spinlock
	rm -f pi_lock
	rm -f pi_free
	rm -f crossroad
