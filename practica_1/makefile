# Nombre del compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

# Nombre del programa
EXEC = bigInt

# Nombre de los archivos fuente
SRC = main.cc usage.cc

# Nombre de los archivos de cabecera 
HEADERS = bigInt.h usage.h

# Nombre de los archivos objeto (cambia todos los .cc por .o)
OBJ = $(SRC:.cc=.o)

.PHONY: all clean

# Reglas por defecto
all: $(EXEC)

# Regla para compilar el ejecutable 
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean: 
	rm -rf $(OBJ) $(EXEC)
