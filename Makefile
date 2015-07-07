CC = g++
#SRCS_FILES = main.cpp
#OBJS_FILES = $(SRCS_FILES:.cpp=.o)
SRCS_FILES = $(wildcard src/*.cpp)
OBJS_FILES := $(patsubst %.cpp,%.o,$(notdir $(wildcard src/*.cpp)) )
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
	rm -f $(EXE) $(OBJS_FOLDER)*
