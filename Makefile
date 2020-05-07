projFinal_OUTPUT: main.o
	g++ main.o -o projFinal_OUTPUT

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o 