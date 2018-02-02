#include <stdio.h>
#include <string.h>

void tokenize(char *a){
    const char s[2] = "-";
    char *token;
    token = strtok(a, s);

    while(token != NULL){
        printf("%s\n",token);
        token = strtok(NULL, s);
    }
    }  

int main(){

     
    // TOKENIZE TEST STUFF
    char test[80];
    printf("Please ENter a string delimited by -:");
    scanf("%s", test);
    tokenize(test);
    return 0;
}