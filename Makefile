CC = g++
SOURCES = main.cpp
OBJS = $(SOURCES:.cpp=.o)
CXXFLAGS = -w
LIBS = -lSDL2
EXE = main

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(CXXFLAGS) $(LIBS) 

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
	rm -f $(EXE) $(OBJS)
