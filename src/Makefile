F = -std=c++20 -Wall -Wextra -Wpedantic -Wfatal-errors
Z = ICS46_hw8.zip
P = graph

def: $P

graph: graph.cpp main.cpp graph.h
	g++ $F graph.cpp main.cpp -o graph

clean:
	/bin/rm -f $P $Z

zip: clean
	zip $Z Makefile main.cpp graph.h graph.cpp small.txt medium.txt large.txt largest.txt
