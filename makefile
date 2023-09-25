CC = g++
FILES = snitch.cpp file.cpp
TARGET = snitch
FLAGS = w

snitch:
	$(CC) $(FILES) -o $(TARGET)

clean:
	rm -rf $(TARGET)