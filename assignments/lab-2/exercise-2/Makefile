all: main.cpp
	g++ main.cpp -o golf

install:
	@cp golf ~/bin
	@echo "Installed golf program"

.PHONY: test
test:
	g++ -g -I. test.cpp -o test
	clear && echo "Running all tests:" && ./test --output=color
	
clean:
	rm -f golf
	rm -f test