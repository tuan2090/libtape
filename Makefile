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
TARGET = $(BIN_DIR)/libtapeexample
SHARED_LIB = $(LIB_DIR)/libtape.so

all: directories $(TARGET)

# Create necessary folders
directories:
	@mkdir -p $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

# Link the final program using the shared library
$(TARGET): $(OBJ_DIR)/libtapeexample.o $(SHARED_LIB)
	$(CC) $(OBJ_DIR)/libtapeexample.o -o $(TARGET) $(LDFLAGS)

# Build the Shared Library (.so) from libtape.o
$(SHARED_LIB): $(OBJ_DIR)/libtape.o
	$(CC) -shared -o $(SHARED_LIB) $(OBJ_DIR)/libtape.o

# Compile the example file (formerly main.c)
$(OBJ_DIR)/libtapeexample.o: $(EXAMPLE_DIR)/libtapeexample.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the library source (formerly tapescript.c)
$(OBJ_DIR)/libtape.o: $(SRC_DIR)/libtape.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)

.PHONY: all directories clean

# Define installation paths
INSTALL_LIB_PATH = /usr/local/lib
INSTALL_INC_PATH = /usr/local/include

INC_LIBTAPE_FILE = include/libtape.h

install: all
	@echo "Installing library and headers..."
	sudo cp $(SHARED_LIB) -t $(INSTALL_LIB_PATH)/
	sudo cp $(INC_LIBTAPE_FILE) -t $(INSTALL_INC_PATH)/
	sudo ldconfig
	@echo "Installation complete."

uninstall:
	rm -f $(INSTALL_LIB_PATH)/libtape.so
	rm -f $(INSTALL_INC_PATH)/libtape.h
	sudo ldconfig


