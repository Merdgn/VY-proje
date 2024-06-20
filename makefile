all: compile run

compile:
	g++ -I./include/ -o ./bin/AVLTree ./src/Main.cpp ./src/AVLTree.cpp ./src/Stack.cpp

run:
	./bin/AVLTree

clean:
	rm -f ./bin/AVLTree






