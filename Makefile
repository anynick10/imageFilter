app: main.o image.o
	gcc -o app main.o image.o -Wall -Wextra -lstdc++

main.o: image.hpp main.cpp
	gcc -c -o main.o main.cpp

image.o: image.hpp image.cpp
	gcc -c -o image.o image.cpp