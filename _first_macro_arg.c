

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


/* #include <GL/glew.h> */

#include <string.h>
#include <time.h>


struct volumeLevel{
    int volumeEnum;
    char * lang[2];
};




struct volumeLevel volumeLevels[3] = {
    {0, {"low", "rendah"}},
    {1, {"medium", "sederhana"}},
    {2, {"high", "ringgi"}}
    
};

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



int main(void){
    enum volumeLevelEnum currentVolume = MEDIUM;
    enum languageEnum currentLanguage = BAHASA;

    // char *volume_string = get_volume_string(aVolume, 0);

    char *high = "high";

    if(currentVolume == MEDIUM){
	char * volumeString = get_volume_string(currentVolume, currentLanguage);
	printf("the current volume is %s", volumeString); 
    } 
    
    return 0;
}
