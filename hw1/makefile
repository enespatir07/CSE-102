all: clean compile run

compile: main.c utils.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test main.c utils.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	clear
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test