# Version 1.0 - 16/04/2013

ROOT = .
SRC  = $(ROOT)/src
INC  = $(ROOT)/include
BIN  = $(ROOT)/bin

CXX      = g++
CXXFLAGS = -pedantic -I$(INC)

LD       = g++
LDFLAGS  =
LIBFLAGS = -lSDL -lSDL_image

CTAGS = @ctags -R --sort=yes --c++-kinds=+px-d --fields=+iaS --extra=+q

SOURCES = $(wildcard $(SRC)/*.cpp)
HEADERS = $(wildcard $(INC)/*.h)
OBJECTS = $(SOURCES:$(SRC)/%.cpp=$(BIN)/%.o)

TARGET = $(ROOT)/app
TAGS   = $(ROOT)/tags

ALL   = all
CLEAN = clean
MRPROPER = mrproper

RM      = @rm
RMFLAGS = -rf

MKDIR      = @mkdir
MKDIRFLAGS = -p

.PHONY: $(ALL) $(CLEAN) $(MRPROPER)

$(ALL): $(TARGET) $(TAGS)

$(TAGS): $(HEADERS) $(SOURCES)
	$(CTAGS) $(INC) $(SRC)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBFLAGS)

$(BIN)/%.o: $(SRC)/%.cpp
	$(MKDIR) $(MKDIRFLAGS) $(BIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CLEAN):
	$(RM) $(RMFLAGS) $(OBJECTS)

$(MRPROPER): $(CLEAN)
	$(RM) $(RMFLAGS) $(BIN) $(TARGET) $(TAGS)
