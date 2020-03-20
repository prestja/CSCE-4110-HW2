INPUT_PATH		:=	input.txt
SORT_PATH		:= 	sort.txt
BALANCE_FACTOR	:=	1
N				:=	10000

default:
	g++ main.cpp avl.cpp -o avl.out 
input:
	g++ create_input1.cpp -o input.out
	./input.out $(N)
run: default input
	./avl.out $(INPUT_PATH) $(BALANCE_FACTOR) 
run_sorted:	default input
	sort $(INPUT_PATH) -o $(SORT_PATH)
	./avl.out $(SORT_PATH) $(BALANCE_FACTOR)
