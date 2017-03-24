#FN = ScrambleString.cpp
FN = complexPointer.cpp
TreePC = binary_tree_pretty_print.cpp
TreePH = binary_tree_pretty_print.h
TreePO = binary_tree_pretty_print.o
UTIL = util.hpp

ListH = list.h

a:$(FN) $(TreePC) $(TreePH) $(TreePO) $(ListH) $(UTIL) Makefile
	g++ -g -std=c++0x $(FN) -o a;

$(TreePO): $(TreePC) $(TreePH) 
	g++ -g -std=c++0x -c $(TreePC);

run:
	./a

clean:
	rm -rf ./a $(TreePO)

