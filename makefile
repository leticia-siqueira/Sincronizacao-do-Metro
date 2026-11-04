
sync_car: sync_car.o sync_car-runner.o
	gcc sync_car.o sync_car-runner.o -o sync_car -pthread

sync_car.o: sync_car.c sync_car.h
	gcc -Wall -Wextra -pthread -c sync_car.c

sync_car-runner.o: sync_car-runner.c sync_car.h
	gcc -Wall -Wextra -pthread -c sync_car-runner.c

clean:
	rm -f *.o sync_car

.PHONY: clean
