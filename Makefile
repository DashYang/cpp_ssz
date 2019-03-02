CC = g++
CFLAGS = -W -Wall
TARGET = test_bin
OBJECTS = test.o cpp_ssz_uint.o cpp_ssz_bytes.o 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o $(TARGET) 
