

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>
#include <fcntl.h>
#include <inttypes.h>




struct Person{
	char * name;
	size_t age;
};

struct Person *create_person(){
	struct Person *p = malloc(100);
	return p;
}


// alloc_person(){
// 	malloc(1);
// }


#define BUFFER_SIZE 10

typedef char * ardie_char;

#define i_have_2_functions(a) (my_first, my_second, a)
#define i_fucking_even(x) ((x!= 0) && ((x & (x-1)))== 0)

char * get_me_a_stupid_array(){
	char * temp = malloc(10);
	int size = 10;
	int i = 0;
	while(i < size)
	{
		temp[i] = 'a';
		i++;
	}
	return temp;
}


struct Arena{	
	unsigned char * buffer;
	size_t buffer_length;
	size_t previous_offset;
	size_t current_offset;
};

uintptr_t align_forward_by_8(uintptr_t ptr) {
	uintptr_t p, a, modulo;
	uintptr_t align = 8;

	// who gives a shit
	// assert(i_fucking_even(align)); 

	p = ptr;
	a = align;
	// Same as (p % a) but faster as 'a' is a power of two
	modulo = p & (a-1);

	if (modulo != 0) {
		p += a - modulo;
		printf("\n we alignned it, AAAA\n");
	}
	return p;
}


typedef struct Arena Arena;

void* arena_alloc(Arena *a, size_t size)
{
	uintptr_t offset = align_forward_by_8((uintptr_t)a->buffer + (uintptr_t)a->current_offset);

	offset = offset - (uintptr_t)a->buffer;
	
	if( offset + size <= a->buffer_length)
	{
		void *ptr = (a->buffer + offset); // who cares about the align variables
		// current_offset += size;
		a->previous_offset = offset;
		a->current_offset = offset + size;
		
		memset(ptr, 0 , size);
		return ptr;
	}
	return NULL;
	
}



#define DEFAULT_ALIGNMENT (2 * sizeof(void *))


void uppercase(ardie_char astring){
	size_t limit = strlen(astring);
	size_t i = 0;
	while(i < limit){
		if( astring[i] >= 'a' && astring[i] <= 'z')
		{
			astring[i] -= 'a' - 'A';
		}
		i++;
	}
}


void add_two(uintptr_t num){
	num = num + 2;
	return ;


}


void _add_two(uintptr_t *num){
	*num = *num + 2;
	return ;
}


void * make_buffer(){
	void * whole_buffer = malloc(5000);
	return whole_buffer;
}


int ardie_strchr_plus(int file_id, char * whole_buffer, char c, int *offset)
{


	int size_read = read(file_id, whole_buffer + *offset, BUFFER_SIZE);
	if( !strrchr(whole_buffer + *offset, '\n'))
	{
		*offset += BUFFER_SIZE;
	}else{
		*offset = 0;
		return size_read;
	}
	
	*(whole_buffer + *offset - 1) = '\n';



	// char * temp = strchr(whole_buffer, '\0');


			

	// int size_read = 10;

	return size_read;
	
}


char * get_next_line(int file_id){

	int offset = 0;
	void * whole_buffer = make_buffer();
	char c = 'm';

	int size_read = ardie_strchr_plus(file_id, (char *)whole_buffer, c, &offset);
	size_read = ardie_strchr_plus(file_id, (char *)whole_buffer, c, &offset);
	
	return whole_buffer;
	
	// return (char *)whole_buffer;
}



int main(void){

	

	// char * testtest = malloc(100);

	// int ff = open("testfile.txt", O_RDWR);

	// read(ff, testtest, 10);
	// read(ff, testtest + 2, 10);

	// printf("\n %p\n", testtest);

	// printf("\n %p\n", testtest +2);

	// return 0;


	int file_id = open("testfile.txt", O_RDWR);
	
	char * line = get_next_line(file_id);
	
	printf("\n get_next_line: \n");
	printf("\n %s\n", line);
	
	free(line);
	
	
	return 0;
		
		

	// ==================================================


	
	// declaring a struct
	struct Person person = {"ardie", 45};



	struct Person *p= create_person();

	p->name = "AL AM AMA AMD AMD's AM's ANSI ANSIs ANZUS ANZUS's AOL AOL's AP API APOs AP's AR ASAP ASCII ASCII's ASCIIs ASL ASL's";

	

	printf("\n full name : %d\n", *(p->name));
	printf("\nsize : %ld\n", sizeof(*(p->name)));


	char *test2 = "hello world";
	printf("\nsize : %ld\n", sizeof(*test2));

	char *super_block = malloc(100);
	int super_offset = 0;

	int old_offset = super_offset;


	int * sprite1 = (int *)super_block;

	*sprite1 = 23;

	printf("\n sprite1: %d\n", *sprite1);
	super_offset = super_offset + sizeof(*sprite1);


	char * sprite2 = (char *)super_block+super_offset;

	sprite2[0] = 'w';
	sprite2[1] = 'a';
	sprite2[2] = 'n';
	
	printf("\n sprite2: %d\n", sprite2[0]);
	printf("\n sprite2: %d\n", super_block[0+super_offset-4]);
	
	printf("\n sizeof(sprite1): %ld\n", sizeof(*sprite1));



	

	unsigned char backing_buffer[256];


	Arena a = {0};
	a.buffer = (unsigned char*)backing_buffer;
	arena_alloc(&a, 10);




	// printf("\nmy name22222 is: %s\n", my_name2);

	// printf("\n how much mislignment it is from 8bytes requirement: %ld\n", ((uintptr_t)&my_name2 % 8));

	
	uintptr_t original = 7;

	add_two(original);
	printf("\n original, %"PRIxPTR"\n", original);
	
	_add_two(&original);
	printf("\n original, %"PRIxPTR"\n", original);



	char astring[] = "wan ahmad ardie";
	// char * _astring = astring;
	uppercase(astring);

	printf("\n my namein uppercase: %s\n", astring);

	char * arena_buffer = malloc(10);

	int ii = 0;
	
	while(ii < sizeof(arena_buffer))
	{
		arena_buffer[ii] = 'p';
		ii++;
	}

	printf("\narena_buffer: %s\n", arena_buffer);




	// ==================================================



	char * whatever = get_me_a_stupid_array();
	


	printf("\nwhatevre: %s\n", whatever);



	

	return 0;

	// ==================================================
	int fd = open("testfile.txt", O_RDWR);


	__S32_TYPE test;


	test = 1099;
	printf("test: %d", test); 


	printf("__wordsize, %d", __WORDSIZE);


	char buffer[10];
	int first = read(fd, buffer, 10);
	printf("first %d", first );
	printf("\n"); 

	printf("buffer: %s", buffer);

	char *res = strchr(buffer, '\0');

	printf("res: %s", res); 

	printf("\n"); 
	printf("strlen %zu", strlen(buffer));
	



	int where = read(fd, buffer, 10);


	printf("where %d", where );
	printf("\n"); 

	
	



	


	


}
