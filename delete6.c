#include <stdio.h>
// #include <cmath>
#include "string.h"
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


char * intern_all_10(FILE * fid, char * input_buffer){

	input_buffer = fgets(input_buffer, 10, fid);
	
	if( )
	{
	}

	

	printf("\n %s\n", input_buffer);
	return input_buffer;
}


int main()
{
	char input_buffer[10];

	// printf("\n Enter a string: \n");

	FILE *fid = fopen("./testfile.txt", "r");




	char *all_input = intern_all_10(fid, input_buffer);

	printf("\n all_input %c\n", all_input[0]);

	// int i = 0;
	// while(i < 10)
	// {		
	// 	printf("\n %c\n", input_buffer[i]);
	// 	i++;
	// }
	




	
}
