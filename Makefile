TARGET=push_swap
CC=gcc
# OBJECTS=input_cleaner.o

$(TARGET): subdir
	$(CC) -g -m64 push_swap.c -Lbasic -linput_cleaner -Llibft -lft -Werror -Wall -Wextra -o push_swap

debug: subdir
	$(CC) -g -m64 -DDEBUG push_swap.c -Lbasic -linput_cleaner -Llibft -lft -Werror -Wall -Wextra -o push_swap


subdir:
	$(MAKE) -C basic
	$(MAKE) -C libft





# Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.


clean: $(CLEANALL)
	rm -f  *.o push_swap
	$(MAKE) -C basic clean
	$(MAKE) -C libft clean




