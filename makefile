PROG = bin/exec
CC = g++ -pthread
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11
OBJS = main.o linkedList.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/

main.o: include/linkedList.h
	$(CC) $(CPPFLAGS) -c src/main.cpp

linkedList.o: include/linkedList.h
	$(CC) $(CPPFLAGS) -c src/linkedList.cpp

clean:
	rm -f build/*.o