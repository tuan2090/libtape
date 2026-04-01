CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11 -fPIC
LDFLAGS = -Llib -ltape

# Paths based on your new tree structure
SRC_DIR = src
EXAMPLE_DIR = example
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# Target names
EXAMPLE_TARGETS = $(BIN_DIR)/example1 $(BIN_DIR)/example2 $(BIN_DIR)/example3
SHARED_LIB = $(LIB_DIR)/libtape.so

all: directories $(EXAMPLE_TARGETS)

# Create necessary folders
directories:
\t@mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

# Link example1
$(BIN_DIR)/example1: $(OBJ_DIR)/example1.o $(SHARED_LIB)
\t$(CC) $(OBJ_DIR)/example1.o -o $(BIN_DIR)/example1 $(LDFLAGS)

# Link example2
$(BIN_DIR)/example2: $(OBJ_DIR)/example2.o $(SHARED_LIB)
\t$(CC) $(OBJ_DIR)/example2.o -o $(BIN_DIR)/example2 $(LDFLAGS)

# Link example3
$(BIN_DIR)/example3: $(OBJ_DIR)/example3.o $(SHARED_LIB)
\t$(CC) $(OBJ_DIR)/example3.o -o $(BIN_DIR)/example3 $(LDFLAGS)

# Build the Shared Library (.so) from libtape.o
$(SHARED_LIB): $(OBJ_DIR)/libtape.o
\t$(CC) -shared -o $(SHARED_LIB) $(OBJ_DIR)/libtape.o

# Compile example files
$(OBJ_DIR)/example1.o: $(EXAMPLE_DIR)/example1.c
\t$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/example2.o: $(EXAMPLE_DIR)/example2.c
\t$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/example3.o: $(EXAMPLE_DIR)/example3.c
\t$(CC) $(CFLAGS) -c $< -o $@

# Compile the library source
$(OBJ_DIR)/libtape.o: $(SRC_DIR)/libtape.c
\t$(CC) $(CFLAGS) -c $< -o $@

clean:
\trm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

.PHONY: all directories clean

# Define installation paths
INSTALL_LIB_PATH = /usr/local/lib
INSTALL_INC_PATH = /usr/local/include

INC_LIBTAPE_FILE = include/libtape.h

install: all
\t@echo "Installing library and headers..."
\tsudo cp $(SHARED_LIB) -t $(INSTALL_LIB_PATH)/
\tsudo cp $(INC_LIBTAPE_FILE) -t $(INSTALL_INC_PATH)/
\tsudo ldconfig
\t@echo "Installation complete."

uninstall:
\trm -f $(INSTALL_LIB_PATH)/libtape.so
\trm -f $(INSTALL_INC_PATH)/libtape.h
\tsudo ldconfig
