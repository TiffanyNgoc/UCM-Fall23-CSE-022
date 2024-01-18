all: main.cpp
	g++ main.cpp -o sonnet

install:
	@cp sonnet ~/bin
	@echo "Installed sonnet program"

.PHONY: test
test:
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	
clean:
	rm -f sonnet
	rm -f test