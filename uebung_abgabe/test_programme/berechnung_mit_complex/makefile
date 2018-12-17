PROG=test_berechnung

CC = g++

FLAGS = -O2

SRCS = complex.cpp test_berechnung.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

%.o:%.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm *.o $(PROG)

# deps:
complex.o: complex.cpp complex.h
test_berechnung.o: test_berechnung.cpp complex.h 	
