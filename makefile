Multi: Driver.o Multilist.o Node.o
	g++ -std=c++11 Driver.o Multilist.o Node.o -o Multi
Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp -o Node.o
Multilist.o: Multilist.cpp Multilist.h
	g++ -c -std=c++11 Multilist.cpp -o Multilist.o
Driver.o: Driver.cpp
	g++ -c -std=c++11 Driver.cpp -o Driver.o
clean:
	rm -f *.o
	rm -f Multi
run:
	make
	./Multi
val:
	make
	valgrind --leak-check=full ./Multi
