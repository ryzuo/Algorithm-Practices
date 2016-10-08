CXX = g++
LINK = g++
CXXFLAGS = -g -m64 -std=c++11
OBJS = common.o \
	   run.o \
	   funutil.o

# Default object
all:run

run:$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	rm *.o

clean:
	rm run *.o
