Multi: Driver.o Multilist.o Node.o
	g++ Driver.o Multilist.o Node.o -o Multi
Node.o: Node.cpp Node.h
	g++ -c Node.cpp -o Node.o
Multilist.o: Multilist.cpp Multilist.h
	g++ -c Multilist.cpp -o Multilist.o
Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o
clean:
	rm -f *.o
	rm -f Multi
run:
	./Multi
