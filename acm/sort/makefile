OBJECTS = select_sort bubble_sort 
ALL: $(OBJECTS)

CC = g++
CFLAGS := --std=c++11

select_sort: select_sort.cc 
	$(CC) $(CFLAGS) $< -o $@

bubble_sort: bubble_sort.cc 
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm  $(OBJECTS)
