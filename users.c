#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"


int createUser(char *user_name, int *age, int *role, char *Path) {

    User *user_instance = malloc(sizeof(User));

    strncpy(user_instance->user_name, user_name, (MAX_USERNAME - 1));
    user_instance->user_name[MAX_USERNAME - 1] = '\0';
    user_instance->user_age = *age;

    

    int err_code = formatUser(user_instance, role, Path);

    // free(user_instance);
    // free(age);
    // free(role);
    // free(user_name);
    return err_code;
};


int formatUser(User *user_instance, int *role, char *Path) {
    char *role_string = malloc(sizeof(char) * 6);
    if (*role == 0) {
        strncpy(role_string, "ADMIN", 5);
        role_string[5] = '\0';
    } else if (*role == 1) {
        strncpy(role_string, "USER", 4);
        role_string[4] = '\0';
    };
    char *formatted_string = malloc(sizeof(User) + 20);
    sprintf(
        formatted_string, 
        "%s,%d,%s\n", 
        user_instance->user_name, 
        user_instance->user_age, 
        role_string
    );

    int save_state = saveUser(formatted_string, Path);

    // free(formatted_string);
    return save_state;
};


int saveUser(char *formatted_user_string, char *Path) {
    int err_code = 1;
    FILE *users_file = fopen(Path, "a");
    
    if(!((users_file) == NULL)) {
        fprintf(users_file, "%s", formatted_user_string);
    } else {
        err_code = 3;        
    };


    return err_code;
};

