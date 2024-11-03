#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"
#include "controllers.h"

int createUserTypeA(char *user_name, int *age, char *Path) {

    int *role = malloc(sizeof(int));
    *role = 0;
    
    int status_code = createUser(user_name, age, role, Path);

    return status_code;
};


int createUserTypeU(char *user_name, int *age, char *Path) {
    
    int *role = malloc(sizeof(int));
    *role = 1;
    
    int status_code = createUser(user_name, age, role, Path);

    return status_code;
};

