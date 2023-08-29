graph: graph.o stack.o queue.o polish_not.o calc.o draw_graph.o
	gcc -Wall -Wextra -Werror graph.o stack.o queue.o polish_not.o calc.o draw_graph.o -o graph

graph.o: graph.c
	gcc -Wall -Werror -Wextra -c graph.c -o graph.o

stack.o: stack.c
	gcc -Wall -Werror -Wextra -c stack.c -o stack.o

queue.o: queue.c
	gcc -Wall -Werror -Wextra -c queue.c -o queue.o

polish_not.o: polish_not.c
	gcc -Wall -Werror -Wextra -c polish_not.c -o polish_not.o

draw_graph.o: draw_graph.c
	gcc -Wall -Werror -Wextra -c draw_graph.c -o draw_graph.o

calc.o: calc.c
	gcc -Wall -Werror -Wextra -c calc.c -o calc.o

.PHONY: rebuild clean all
 
rebuild: clean all

clean:
	rm -rf *.o graph

all: graph