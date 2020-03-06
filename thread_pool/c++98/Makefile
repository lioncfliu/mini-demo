CC = g++

CXX_FLAGS += -g -Wall -Wextra
TARGET = main 
OBJS = main.o thread_pool.o thread_job_4test.o
LIBS = -lpthread

CLEANUP = rm -f $(TARGET)

all: $(TARGET)
$(TARGET): $(OBJS)
		$(CC) $(CXX_FLAGS) $(OBJS)  -o $@  $(LIBS)

main.o:	thread_pool.h thread_job_4test.h
thread_pool.o:	thread_pool.h thread_job.h
thread_job_4test.o:	thread_job_4test.h thread_job.h

clean:
		rm $(TARGET) $(OBJS)
