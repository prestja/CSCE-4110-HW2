INPUT_PATH		:=	input.txt
SORT_PATH		:= 	sort.txt
BALANCE_FACTOR	:=	1
N				:=	1000000

default:
	g++ -Ofast main.cpp avl.cpp -o avl.out 
	g++ matrixs.cpp matrix.cpp -o matrix.out
input:
	g++ create_input1.cpp -o input.out
	./input.out $(N)
avl: default input
	./avl.out $(INPUT_PATH) $(BALANCE_FACTOR) 
avl_sorted:	default input
	sort $(INPUT_PATH) -o $(SORT_PATH)
	./avl.out $(SORT_PATH) $(BALANCE_FACTOR)
Matrix: default
	./matrix.out 20.txt 30.txt 100.txt 500.txt 100x20.txt 100x20s80.txt 100x25.txt  100x25s80.txt 100x50.txt 100x50s80.txt 100x80.txt 100x80s80.txt 20s10.txt 20s50.txt 20s80.txt 500s10.txt 500s50.txt 500s80.txt