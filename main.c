#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "users.h"


void main(void) {

    char users_Path[] = "users.txt";

    printf("\n Enter user name: ");
    char *user_name = malloc(sizeof(char) * 65); 
    scanf("%s", user_name);

    printf("\n Enter user age: ");
    int age;
    scanf("%d", &age);

    createUser(user_name, age, 0, users_Path);
    createUser(user_name, age, 1, users_Path);
    
}