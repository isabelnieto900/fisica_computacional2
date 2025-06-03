CXX = g++
CXXFLAGS = -Wall -Iinclude -I. -I/mnt/c/Users/laura/Downloads/eigen-3.4.0
SRC = src/main.cpp src/funciones.cpp
 
all: clean main run

clean:
	rm -f main.exe main

main: $(SRC)
	$(CXX) $(CXXFLAGS) -o main $(SRC)

run: main
	./main

