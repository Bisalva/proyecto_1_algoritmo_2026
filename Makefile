CC      = gcc
CFLAGS  = -Wall -Wextra -Iincs
SRC     = src/main.c src/deportistas.c src/ordenamiento.c src/busqueda.c src/menu.c src/experimento.c
OBJ     = $(patsubst src/%.c, obj/%.o, $(SRC))
TARGET  = build/sistema

.PHONY: all clean clean-db folders run

all: folders $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

folders:
	mkdir -p obj build db plots

run: all
	./$(TARGET)

clean:
	rm -rf obj build

clean-db:
	rm -rf db
