all: laba

laba: main.o func.o
	g++ main.o func.o

main.o: main.cpp
	g++ -c main.cpp

func.o: func.cpp
	g++ -c func.cpp

clean:
	rm -rf *o laba