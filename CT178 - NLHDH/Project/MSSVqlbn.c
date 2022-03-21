#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int main(){
    unsigned long frame[MAX_N] = {6,5,4,2,7,3,1};
    char *filename = malloc(100);
    fgets(filename, 100, stdin);
    if(filename[strlen(filename)-1] == '\n')
        filename[strlen(filename)-1] = '\0';
    FILE *f = fopen(filename, "r");
    while(!feof(f)){
        unsigned long lg_address;
        fscanf(f, "%ld", &lg_address);
        printf("%ld\n", frame[lg_address/128] * 128 + (lg_address % 128));
    }
}
