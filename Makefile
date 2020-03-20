default:
	g++ main.cpp avl.cpp -o avl.out 
run: default
	./avl.out
input:
	g++ create_input1.cpp -o input.out
	./input.out 10
