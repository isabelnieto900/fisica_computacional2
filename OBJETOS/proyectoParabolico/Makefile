# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 -Iinclude
SRC = src/main.cpp src/funciones.cpp src/graficador.cpp
BIN = tiro

# Regla principal
all: $(BIN)

# Enlazado final
$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

# Ejecutar y graficar
plot: $(BIN)
	./$(BIN)

# Limpiar binarios y archivos generados
clean:
	rm -f $(BIN) results/datos.dat *.png

.PHONY: all clean plot
