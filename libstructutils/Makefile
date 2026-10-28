TARGET=libstructutils.a
CC=gcc

OBJECTS=libfilterinput.o libfillstruct.o libfree.o libdebug.o


$(TARGET): $(OBJECTS)
	ar rc $(TARGET) $(OBJECTS)



$(OBJECTS): %.o: %.c
	$(CC) -shared -c -fPIC $^ -o $@









# Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.


clean:
	rm -f  *.o *.a
