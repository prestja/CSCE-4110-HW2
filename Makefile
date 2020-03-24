INPUT_PATH		:=	input.txt
SORT_PATH		:= 	sort.txt
BALANCE_FACTOR	:=	1
N				:=	10000000

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
input2:
	g++ makematrix.cpp -o Mmake.out
	./Mmake.out 20 20 0 20.txt
	./Mmake.out 20 20 10 20s10.txt
	./Mmake.out 20 20 50 20s50.txt
	./Mmake.out 20 20 80 20s80.txt
	./Mmake.out 30 30 0 30.txt
	./Mmake.out 100 100 0 100.txt
	./Mmake.out 500 500 0 500.txt
	./Mmake.out 500 500 10 500s10.txt
	./Mmake.out 500 500 50 500s50.txt
	./Mmake.out 500 500 80 500s80.txt
	./Mmake.out 100 20 0 100x20.txt
	./Mmake.out 100 20 80 100x20s80.txt
	./Mmake.out 100 25 0 100x25.txt
	./Mmake.out 100 25 80 100x25s80.txt
	./Mmake.out 100 50 0 100x50.txt
	./Mmake.out 100 50 80 100x50s80.txt
	./Mmake.out 100 80 0 100x80.txt
	./Mmake.out 100 80 80 100x80s80.txt
	
matrix: default input2
	./matrix.out 20.txt 30.txt 100.txt 500.txt 100x20.txt 100x20s80.txt 100x25.txt  100x25s80.txt 100x50.txt 100x50s80.txt 100x80.txt 100x80s80.txt 20s10.txt 20s50.txt 20s80.txt 500s10.txt 500s50.txt 500s80.txt
	rm *.txt
