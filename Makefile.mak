CXX = g++
CXXFLAGS = -std=c++11 -pedantic -fopenmp

SRCS = main.cpp Queries_NW.cpp Queries_BL.cpp my_strings.cpp genomeprocessing.cpp
OBJS = $(SRCS:.cpp=.o)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main