CC = g++
SRCS_FILES = main.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)
OBJS_FOLDER = objs/
OBJS = $(OBJS_FOLDER)$(OBJS_FILES)
CXXFLAGS = -w
LIBS = -lSDL2 -lSDL2_image
VPATH = src objs
EXE = main

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS_FILES)
	$(CC) $(OBJS) -o $(EXE) $(CXXFLAGS) $(LIBS) 

%.o: %.cpp
	$(CC) $(CXXFLAGS) $< -c -o $(OBJS_FOLDER)$@ $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
