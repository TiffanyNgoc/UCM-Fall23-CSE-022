all: main.cpp
	g++ main.cpp -o postcard

install:
	@cp postcard ~/bin
	@echo "Installed postcard program"

.PHONY: test
test:
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	
clean:
	rm -f postcard
	rm -f test