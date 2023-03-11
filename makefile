CC = g++
CFLAGS = -Wall
LIBS = `pkg-config --cflags --libs opencv4`
TARGET = rhudi_prime
SRC = main.cpp

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

clean:
	rm -f $(TARGET)