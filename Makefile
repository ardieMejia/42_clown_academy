TARGET=push_swap
CC=gcc
# OBJECTS=input_cleaner.o
SRCS = push_swap.c simple.c medium.c

$(TARGET): subdir
	$(CC) -g -m64  $(SRCS) -Lgetters -lgetters -Llibstructutils -lstructutils -Llibhardcode -lhardcode -Lliboperations -loperations -Llibft -lft -Werror -Wall -Wextra -o push_swap

debug: subdir
	# $(CC) -g -m64 -DDEBUG push_swap.c simple/simple.c medium/medium.c -Lgetters -lgetters -Llibstructutils -lstructutils -Llibft -lft -Lliboperations -loperations -Werror -Wall -Wextra -o push_swap
	$(CC) -g -m64 -DDEBUG $(SRCS) -Lgetters -lgetters -Llibstructutils -lstructutils -Llibhardcode -lhardcode -Lliboperations -loperations -Llibft -lft -Werror -Wall -Wextra -o push_swap


subdir:
	$(MAKE) -C libstructutils
	$(MAKE) -C libft
	$(MAKE) -C getters
	$(MAKE) -C liboperations
	$(MAKE) -C libhardcode





# Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.


clean: $(CLEANALL)
	rm -f  *.o push_swap
	$(MAKE) -C libstructutils clean
	$(MAKE) -C libft clean
	$(MAKE) -C getters clean
	$(MAKE) -C liboperations clean
	$(MAKE) -C libhardcode clean





