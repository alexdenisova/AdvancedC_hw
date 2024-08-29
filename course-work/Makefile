all: graph

graph: main.c roots.c integrals.c functions.c
	gcc -I . -o graph main.c roots.c integrals.c functions.c

clean:
	rm -rf *.o graph
