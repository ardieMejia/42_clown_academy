
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

void change_the_2nd_of_int_list(uintptr_t *num1){
	*num1 =  230;
	printf("\n num1 as int%d\n", (int)(*num1) );
}


int main(){


	uintptr_t num1 = 10;
	printf("\nnum1%ld\n", num1);
	change_the_2nd_of_int_list(&num1);


	printf("\nnum1%ld\n", num1);

	
	return 0;
}
