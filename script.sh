#!/bin/bash
g++ -c *.cpp
g++ -o exec *.o
for i in $(ls *.txt); 
do 
	echo "Executant jocs de proves: $i"
	./exec <"$i" 2> /dev/null
	echo
	
done