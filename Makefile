COMPILER=g++-5 --std=c++11
EXECUTABLES=test.out
all:
	make $(EXECUTABLES)

test.out: test.cpp hashtable.hpp
	$(COMPILER) -o $@ $^

clean:
	rm -f $(EXECUTABLES)
