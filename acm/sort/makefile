OBJECTS = quick_sort insert_sort select_sort bubble_sort 
ALL: $(OBJECTS)

CC = g++
CFLAGS := --std=c++11

quick_sort: quick_sort.cc
	$(CC) $(CFLAGS) $< -o $@

insert_sort: select_sort.cc 
	$(CC) $(CFLAGS) $< -o $@

select_sort: select_sort.cc 
	$(CC) $(CFLAGS) $< -o $@

bubble_sort: bubble_sort.cc 
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm  $(OBJECTS)
