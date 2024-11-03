#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "users.h"
#include "controllers.h"


void main(void) {

    char users_Path[] = "users.txt";

    printf("\n Enter user name: ");
    char *user_name = malloc(sizeof(char) * 65); 
    scanf("%s", user_name);

    printf("\n Enter user age: ");
    int *age = malloc(sizeof(int));
    scanf("%d", age);
    
    

    createUserTypeA(user_name, age, users_Path);
    createUserTypeU(user_name, age, users_Path);

    
    
}