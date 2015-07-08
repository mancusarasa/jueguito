CC = g++
SRCS_DIR = src/
OBJS_DIR = objs/
SRC = $(wildcard $(SRCS_DIR)*.cpp)
OBJS_FILES := $(patsubst %.cpp,%.o,$(notdir $(SRC)))
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_FILES))
CXXFLAGS = -w -ggdb
LIBS = -lSDL2 -lSDL2_image
EXE = main

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(CXXFLAGS) $(LIBS) 

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CC) $(CXXFLAGS) $< -c -o $@ $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
