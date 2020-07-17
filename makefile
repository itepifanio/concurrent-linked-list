PROG = bin/exec
CC = g++ -pthread
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++17
OBJS = main.o linkedList.o handler.o

$(PROG) : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o build/

main.o: include/linkedList.h
	$(CC) $(CPPFLAGS) -c src/main.cpp

linkedList.o: include/linkedList.h
	$(CC) $(CPPFLAGS) -c src/linkedList.cpp

handler.o: include/handler.h include/linkedList.h
	$(CC) $(CPPFLAGS) -c src/handler.cpp	

clean:
	rm -f build/*.o