CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/main.c src/telemetry.c src/visualization.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = telemetry_visualization

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean