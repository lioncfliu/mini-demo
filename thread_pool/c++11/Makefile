CC = g++

CXX_FLAGS += -g -Wall -Wextra -std=c++11
TARGET = main 
OBJS = main.o thread_pool.o 
LIBS = 

CLEANUP = rm -f $(TARGET)

all: $(TARGET)
$(TARGET): $(OBJS)
		$(CC) $(CXX_FLAGS) $(OBJS)  -o $@  $(LIBS)

main.o:	thread_pool.h main.cpp
		$(CC) $(CXX_FLAGS) thread_pool.h main.cpp  -o $@  
thread_pool.o: 	thread_pool.h thread_pool.cpp
		$(CC) $(CXX_FLAGS) thread_pool.h thread_pool.cpp  -o $@  

clean:
		rm $(TARGET) $(OBJS)
