# Nombre del compilador y flags
CC=g++
CFLAGS=-std=c++17 -Wextra -I$(INCLUDE_DIR)
LDFLAGS=
EXECUTABLE=myProgram
RESU=resultados.txt

# Listado de archivos fuente y objetos
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build

# Obtén la lista de archivos fuente y genera la lista de archivos objeto
SRCS=$(wildcard $(SRC_DIR)/*.cc)
OBJS=$(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# En esta lista definimos únicamente los archivos de cabecera y el archivo principal
HEADERS=$(wildcard $(INCLUDE_DIR)/*.h)
MAIN_SRC=$(SRC_DIR)/main.cc

# Reglas de construcción
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/main.o: $(MAIN_SRC) $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $(MAIN_SRC)

clean:
	-rm -rf $(BUILD_DIR) $(EXECUTABLE) $(RESU)
	@echo "All cleaned!"
