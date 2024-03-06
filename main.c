#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* major[12] = {"C","C#","D","D#","E","F","F#","G","Ab","A","Bb","B"};
char* major2[12] = {"c","c#","d","d#","e","f","f#","g","ab","a","bb","b"};
char* minor[12] = {"Cm","C#m","Dm","D#m","Em","Fm","F#m","Gm","Abm","Am","Bbm","Bm"};
char* minor2[12] = {"cm","c#m","dm","d#m","em","fm","f#m","gm","abm","am","bbm","bm"};

bool is_minor(char chord[]){
    if(strlen(chord)>=2 && (chord[1]=='m' || chord[2]=='m')){
        return true;
    }else{
        return false;
    }
}

char* get_trance_minor(char* chord, int trance_num){
    int j;
    int trance = 0;
    for(j=0;j<12;j++){
        if(!strcmp(chord,minor[j]) || !strcmp(chord,minor2[j])){
            if((j + trance_num) >= 12){
                trance = (j + trance_num) - 12;
                return minor[trance];
            }else{
                return minor[j + trance_num];
            }
        }
    }
    return 0;
}

char* get_trance_major(char* chord, int trance_num){
    int j;
    int trance = 0;
    for(j=0;j<12;j++){
        if(!strcmp(chord,major[j]) || !strcmp(chord,major2[j])){
            if((j + trance_num) >= 12){
                trance = (j + trance_num) - 12;
                return major[trance];
            }else{
                return major[j + trance_num];
            }
        }
    }
    return 0;  
}

int main(int argc, char* argv[]){
    int i;
    if(argc>=3){
        for (i=1;i<argc-1;i++){
            if(is_minor(argv[i])){
                printf("%s ",get_trance_minor(argv[i], atoi(argv[argc-1])));
            }else{
                printf("%s ",get_trance_major(argv[i], atoi(argv[argc-1])));
            }
        }
        printf("\n");
    }
    return 0;
}