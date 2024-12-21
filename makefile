HW_1 : HW_1.o genome.o
	g++ -o HW_1 HW_1.o genome.o

HW_1.o : HW_1.cpp
	g++ -c HW_1.cpp -o HW_1.o

genome.o: genome.cpp
	g++ -c genome.cpp -o genome.o

clean:
	rm HW_1 HW_1.o
