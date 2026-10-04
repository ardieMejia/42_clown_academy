*This project has been created as part of the 42 curriculum by arwan*

## Description
The purpose of this project is to create a custom library of C functions. All files and their functions follow the criteria stated inside the Libft PDF.

## Instructions
Run "make" to compile all the .c files. An object files for each .c file will be created in the main directory. You can run "make clean" to delete all object files. Running "make fclean" will include libft.a to be deleted as well with the object files.

You can also make individual files, such as "make <filename>.o" followed by "make libft.a", thus saving time when making changes to only a single function
```
make <filename>.o
make libft.a
```
I you wish to run it against your own test, and say it resides in a main file (which is normally what happens), you may then test it with
```
gcc main.c <relative-location-of-libft>/libft.a <other-relative-directory>/<other-utilities-you-may-have>.a -Wextra -Wall -Werror -o output
./output
```
## Resources
- https://www.cs.cmu.edu/,
- https://man.freebsd.org,
- https://stackoverflow.com,
- https://www.geeksforgeeks.org/.
- Some minimal AI in case when Im clearly misunderstanding something
## Library includes these functions
# Character operations
- ft_isalpha : checks for an alphabetic character
- ft_isdigit : hecks for a digit (0 through 9)
- ft_isalnum : checks for an alphanumeric character
- ft_isascii : checks if its part of ASCII character set
- ft_isprint : checks for any printable character including space
- ft_toupper : These functions convert lowercase letters to uppercase
- ft_tolower : These functions convert uppercase letters to lowercase
# String operations
- ft_strlen : calculate the length of a string
- ft_strlcpy : copy strings, returns the total length of the string they tried to createa
- ft_strlcat : concatenate strings, returns the total length of the string they tried to createa
- ft_strchr : returns a pointer to the first occurrence of a character in a string
- ft_strrchr : returns a pointer to the last occurrence of a character in a string
- ft_strncmp : compares the two strings s1 and s2, returns an integer indicating the result of the comparison
- ft_strnstr : locates the first occurrence of the null-terminated string little in the string big, where not more than len characters are searched
- ft_substr : Allocates memory and returns a substring from a string. Argument is start of substring and maximum length
- ft_strjoin : Allocates memory and returns a new string, resulting from concatenating s1 and s2.
- ft_strtrim : Allocates memory and returns a copy of string with characters from set removed from the beginning and the end
- ft_split : Allocates memory and returns an array of strings obtained by splitting it using a delimiter
- ft_strmapi : Applies a function to each character of the string s. Result created using malloc
- ft_striteri : Applies a function to each character of the string passed as argument, passing its index as the first argument
# Memory manipulations
- ft_calloc : allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.  The memory is set to zero.
- ft_memset : fills the first n bytes of the memory area pointed to by s with the constant byte c.
- ft_bzero : erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.
- ft_memcpy : copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.
- ft_memmove : copies n bytes from memory area src to memory area dest.  The memory areas may overlap
- ft_memchr : scans the initial n bytes of the memory area pointed to by s for the first instance of c.
- ft_memcmp : compares the first n bytes of the memory areas s1 and s2. 
- ft_strdup : returns a pointer to a new string which is a duplicate of the string s.  Memory created with malloc, and can be freed with free(3).
# Some number stuff
- ft_atoi : converts a string pointed to its int representation, while skipping some printable white space types
- ft_itoa :  converts an int pointed to its string representation. 
# File stuff 
- ft_putchar_fd : Outputs the character ’c’ to the specified file descriptor
- ft_putstr_fd : Outputs a string to the specified file descriptor.
- ft_putendl_fd  : Outputs a string to the specified file descriptor followede by a newline
- ft_putnbr_fd : Outputs a integer to the specified file descriptor
# Linked list operations
- ft_lstnew : Allocates memory, returns a new node, assigns a content member, next intitliazed to NULL
- ft_lstadd_front : Adds the node ’new’ at the beginning of the list
- ft_lstsize : Counts the number of nodes in the list
- ft_lstlast : Returns the last node of the list
- ft_lstadd_back : Adds the node ’new’ at the end of the list
- ft_lstdelone : Takes a node as parameter and frees its content using a function. Free the node itself but does NOT free the next node
- ft_lstclear : Deletes and frees the given node and all its successors, using a function fed-in and free(3). Finally, set the pointer to the list to NULL
- ft_lstiter : Iterates through the list and applies a function to the content of each node
- ft_lstmap : Iterates through a list, applies a function to each node’s content, creates a new list resulting of the successive applications of that function. The "del" function is used to delete the content of a node at any moment of failure.
