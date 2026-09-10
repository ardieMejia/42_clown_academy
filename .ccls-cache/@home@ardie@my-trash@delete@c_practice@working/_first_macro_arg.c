

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <stddef.h>



/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>
#include <assert.h>

struct volumeLevel{
	int volumeEnum;
	char * lang[2];
};



// void *memmove(void *dest, const void *src, size_t n)
// {
// 	size_t i = n;

// 	char *d = (char *)dest;
// 	char *s = (char *)src;

// 	while(i > 0 ){
// 		printf("%d", (int)i); 
// 		*(d + i) = *(s + i);
// 		i--;
// 	}

	
	


// 	return dest;
// }






#define INVISIBLE					\
	Y("value is", "whatever", 1)			\
	Y("value is", "who cares", 2)			\
	Y("value is", "whatnoe", 3)			\
	Y("value is", "haha", 4)



struct volumeLevel volumeLevels[3] = {
	{0, {"low", "rendah"}},
	{1, {"medium", "sederhana"}},
	{2, {"high", "ringgi"}}
    
};

char *createArray (){
	char *_return = malloc(10);
	int i = 0;
	while (i < 10){
		_return[i] = 'a' + i;
		i++;
		
	}
	return _return;
}

int is_al(char c){
	if(c >='a' && c<='z')
		return 1;
	return 0;
}


int get_input_n_only(){
	char n_only[2];
	printf("enter any text"); 
	fgets(n_only, 2, stdin);
	printf("%s", n_only);
	if(n_only[0] == 'n')
		return 1;
	return 0;
}

void push_b(char *_a, char *_b){
	int i = 0;
	while(_a[i] == '-' && _a[i] != '\0')
		i++;
	int j = 9;
	while(_b[j] != '-')	       
		j--;
       _b[j] = _a[i];
       _a[i] = '-';
	return;
}

void push_a(char *_a, char *_b){
	int j = 9;
	while(_b[j] == '-' && _b[j] != '\0')
		j++;
	int i = 0;
	while(_a[i] != '-') // change of reference	       
		i--;
       _a[i] = _b[j];
       _b[j] = '-';
	return;
}



void display(char *_a, char *_b){
	int i =0;
	while(i < 10){
		printf("%c   %c", _a[i], _b[i]);
		printf("\n"); 
		i++;
	}
	return;
}


void display_parent(char *_a, char *_b){
	int i =0;
	while(i < 10){
		printf("%c   %c", _a[i], _b[i]);
		printf("\n"); 
		i++;
	}
	return;
}

void apply(char * _a, char * _b,void (f) (char *, char *)){
	f(_a ,_b);
	return;
}


enum volumeLevelEnum{
	LOW,
	MEDIUM,
	HIGH
};

enum languageEnum{
	ENGLISH,
	BAHASA
};



char*	get_volume_string(int currentVolume, int currentLanguage){
	return volumeLevels[currentVolume].lang[currentLanguage];
}


int my_atoi(char * astring){
	while (*astring == ' ')
		astring++;
	return -99;
}




char * letsMove(char ** test_string){
	char * return_string = (char *)malloc(5);
	*return_string = 'X';
}

// int tillNextSpace(char * src){
// 	int i++;
// 	while (*(src + i) != ' '){
// 		i++;
// 	}
// 	while(*(src + i) = ' '){
// 		i++;
// 	}
// 	return_string;
// }


// char * move_back_1(char *dest, char *src){
// 	int i = 0;
// 	int j = 0;

// 	int size = 5;

// 	size = tillNextSpace(dest);


// 	if(dest < src)
// 	{
// 		while(i < size){
// 			*(dest + i) = *(src + i);
// 			i++;
// 		}
// 	}

	
// 	return dest;
// }


void my_printf(char * value, char * someString, int a){
	printf("%s %d", someString, a); 
	
}


int main(void){
	
// #define Y(value, string, a) my_printf(value,string , a);
// 	INVISIBLE
// #undef Y

	char * var1 = "I cant be changed";
	char var2[30];
	int i = 0;
	while(var1[i] != '\0'){
		var2[i] = var1[i];
		i++;
	}

	var2[2] = '_';
	printf("whatever I dont care anymore: %s", var1);

	char * a = createArray();
	char * b= createArray();

	int iii = 0;
	while(iii<10)
	{
		b[iii] = '-';
		iii++;
	}



	while(get_input_n_only())
	{
		// char display = createDisplay(cool);
		apply(a, b, push_b);
		apply(a, b, push_a);		
	}
		// display(a,b);

	
	int atoi_result;
	char * test_string = "hello there";

	test_string++;

	printf("current string: %s", test_string);
	printf("\n");

	char * feed_string = letsMove(&test_string);

	printf("feed string: %s", feed_string); 
	printf("\n");

	printf("current string: %s", test_string);
	printf("\n");
    
    
#ifdef __unix__
#endif
	char *OS = "Linux";
	static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

    
	enum volumeLevelEnum currentVolume = MEDIUM;
	enum languageEnum currentLanguage = BAHASA;

	assert(currentVolume == MEDIUM);
	static_assert(03301 == 1729);

	// char *volume_string = get_volume_string(aVolume, 0);

	char *high = "high";

	if(currentVolume == MEDIUM){
		char * volumeString = get_volume_string(currentVolume, currentLanguage);
		printf("the current volume is %s", volumeString); 
	}
	if(__STDC_VERSION__){
		printf("\n"); 
		printf("gcc version %ld", __STDC_VERSION__);
		printf("\n"); 
	}




	// ==================================================    
	// ==================================================    
	// ==================================================




	char _original[] = "  12345  12345";
	char *original = _original;




	

	// char* new_original = move_back_1(original, original + 3);
	


	// printf("new originl: %s", new_original); 



	int x = 10;
	int *p = &x;

	printf("%d\n", *p);   // 10
	printf("%p\n", p);    // address of x
	

	

	return 0;
}
