CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -Iinclude
EXECUTABLE=bigint

OBJ=number bigint board

all: src/main.cc $(OBJ:%=build/%.o)
	$(CC) $(CFLAGS) -o $(EXECUTABLE).out $^

build/%.o: src/%.cc include/%.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o build/$*.o src/$*.cc

clean:
	-rm build/*.o
	-rm $(EXECUTABLE).out
	@echo "All cleaned!"

.PHONY: clean
