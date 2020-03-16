.SUFFIXES:
.PHONY: all clean

PWD := $(shell pwd)
CXX := g++
CXXFLAGS := -Wall -g --std=c++11 -pthread
INCLUDES := -I $(PWD)/include
TARGET := main

#object dir
OBJDIR = $(PWD)/object

SRCS := $(wildcard $(PWD)/*.cpp)
OBJS = $(patsubst $(PWD)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET):  $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@


$(OBJS):$(OBJDIR)/%.o:$(PWD)/%.cpp
	#@echo $@
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -c -o $@

clean:
	rm -rf $(OBJDIR)/*.o


