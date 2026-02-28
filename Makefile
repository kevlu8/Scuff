# Project settings
EXE      ?= hcechessbot

# Compilers
CXX      := g++
WINCXX   := x86_64-w64-mingw32-g++

# Flags
BASEFLAGS   := -std=c++17 -m64
OPTFLAGS    := -O3 -flto=auto
DEBUGFLAGS  := -g -march=x86-64-v3 -fsanitize=address,undefined

# Sources & objects
SRCS  := $(wildcard *.cpp)
HDRS  := $(wildcard *.hpp pzstl/*.hpp)
OBJS  := $(SRCS:.cpp=.o)
DEPS  := $(OBJS:.o=.d)

.PHONY: all native debug clean test debug-test

# Default: native build
all: native

native: CXXFLAGS = $(BASEFLAGS) $(OPTFLAGS) -march=native
native: $(EXE)

debug: CXXFLAGS = $(BASEFLAGS) $(DEBUGFLAGS)
debug: $(EXE)

# Link final binary
$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete. Run with ./$(EXE)"

# Compile objects with dependency generation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include generated dependency files
-include $(DEPS)

# Tests
test: CXXFLAGS = $(BASEFLAGS) $(OPTFLAGS)
test: $(OBJS)
	$(AR) rcs test/objs.a $(OBJS)
	$(MAKE) -C test CXXFLAGS="$(CXXFLAGS)"

debug-test: CXXFLAGS = $(BASEFLAGS) $(DEBUGFLAGS)
debug-test: $(OBJS)
	$(AR) rcs test/objs.a $(OBJS)
	$(MAKE) -C test CXXFLAGS="$(CXXFLAGS)" debug

# Cleanup
clean:
	@echo "Cleaning up..."
	rm -f $(EXE) *.exe
	rm -f $(OBJS) $(DEPS)
	rm -f test/objs.a
	$(MAKE) -C test clean
