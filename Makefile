CC = g++
CFLAGS = -W -Wall


TEST_UINT = test_uint
TEST_BYTES = test_bytes
TEST_CODEC = test_codec
TEST_TARGETS = $(TEST_UINT) $(TEST_BYTES) $(TEST_CODEC)

all: $(TEST_TARGETS) 

SRC_OBJECTS = cpp_ssz_uint.o cpp_ssz_bytes.o 

$(TEST_UINT): test_uint.o $(SRC_OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_BYTES): test_bytes.o $(SRC_OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

$(TEST_CODEC): test_codec.o $(SRC_OBJECTS) 
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o $(TEST_TARGETS) 
