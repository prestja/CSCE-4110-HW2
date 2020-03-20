INPUT_PATH		:=	input.txt
BALANCE_FACTOR	:=	1

default:
	g++ main.cpp avl.cpp -o avl.out 
run: default
	./avl.out $(INPUT_PATH) $(BALANCE_FACTOR) 
input:
	g++ create_input1.cpp -o input.out
	./input.out 10
