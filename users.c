#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "users.h"


int createUser(char *user_name, int age, int role, char *Path) {

    User *user_instance = malloc(sizeof(User));

    strncpy(user_instance->user_name, user_name, (MAX_USERNAME - 1));
    user_instance->user_name[MAX_USERNAME - 1] = '\0';
    user_instance->user_age = age;

    if (role == 0) {
        user_instance->user_role = ADMIN;
    } else if (role == 1) {
        user_instance->user_role = USER;
    };

    int err_code = formatUser(user_instance, Path);

    return err_code;
};


int formatUser(User *user_instance, char *Path) {
    char *formatted_string = malloc(sizeof(User) + 20);
    sprintf(
        formatted_string, 
        "%s,%d,%d\n", 
        user_instance->user_name, 
        user_instance->user_age, 
        user_instance->user_role
    );

    int save_state = saveUser(formatted_string, Path);

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

