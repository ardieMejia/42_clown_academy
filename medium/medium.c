#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../libstructutils/libfillstruct.h"
#include "../libstructutils/libfilterinput.h"
#include "../libstructutils/libdebug.h"
#include "../getters/libgetters.h"
#include "../libft/libft.h"
#include "../libstructutils/libfree.h"
#include "../liboperations/liboperations.h"


int  push_2_to_b(Stack * game_stack){
	int err = 0; 
	int i = 0;
	while (i < 2){		
		err = pb(game_stack);
		if(err)
			return 1;
		i++;
	}	
	return 0;
}

