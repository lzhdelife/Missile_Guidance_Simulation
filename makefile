### Compiler & flags
CC=gcc
CFLAGS=-c -lm

### Directories
SRC_DIR=src
OBJ_DIR=obj
HEAD_DIR=headers

### Executable name
EXEC=RK4_2

### Sources (in src directory)
SOURCES=$(addprefix $(SRC_DIR)/, \
	main.c RK4.c io.c memory.c)

### Objects (in obj directory)
OBJECTS=$(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

### Rules: #######################################

### General target (executable):
all: $(EXEC)

### How to make the executable:
$(EXEC): $(OBJECTS) 
	$(CC) $^ -o $@ -lm

### How to make every object:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

### How to clean up:
clean: 
	rm $(OBJECTS) $(EXEC)
