TARGET=libgetters.a
CC=gcc
OBJECTS=libgetters.o

$(TARGET): $(OBJECTS)
	ar rc $(TARGET) $(OBJECTS)



$(OBJECTS): %.o: %.c
	$(CC) -shared -c -fPIC $^ -o $@



clean:
	rm -f  *.o *.a
