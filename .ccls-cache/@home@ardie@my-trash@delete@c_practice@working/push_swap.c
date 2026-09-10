

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>



int get_max(int array[], int n)
{
		// sizeof(arr) / sizeof(arr[0])
	int i = 0;
	int max = array[0];
	while(i < n )
	{
		if( array[i] > max)
			max = array[i];
		i++;
	}
}

int get_min(int array[], int n)
{
	int i = 0;
	int min = array[0];
	while(i < n )
	{
		if( array[i] < min)
			min = array[i];
		i++;
	}
}

int * normalize_to_3(int stack_a[], n){
	while(stack_a)
	{
		
	}
}

void order(int * n_stack_a, int index1, int index2, int index3)
{
	int equals = 0;
	if(n_stack_a[0] = ){
		
	}

	return equals;
}

int * ra(int stack_a[]){
	printf("\n we are rotating %d\n", stack_a[0]);
}

int * sort_array(int stack_a[])
{
	if(order_equal(normalize_to_3(stack_a), 3,2,1))
	{
		ra(stack_a);
		ra(stack_a);
	}	
}


void display(int stack_a[])
{
	printf("\n ================================================== \n");
	while(i < 3){
		printf("%d \n", stack_a[i]);
		i++=;
	}
	printf("\n ================================================== \n");
}

int main (int argc, char ** argv){
	int stack_a[] = {1, 2, 3};
	sort_array(stack_a);

	display(stack_a);
	

	return 0;
	
}


