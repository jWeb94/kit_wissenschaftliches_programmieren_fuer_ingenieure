PROG = planeten

FLAGS = -Wall -O2

CC = g++

SRCS = particle_dynamics.cpp verlet.cpp

OBJ = $(SRCS:.cpp=.o)

all: $(SRCS) $(PROG)

$(PROG): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp
	$(CC)  $(FLAGS) -c $<


clean:
	rm -rf *.o $(PROG)

## dependencies

verlet.o: verlet.cpp verlet.h particle.h
particle_dynamics.o: particle_dynamics.cpp particle.h verlet.h



