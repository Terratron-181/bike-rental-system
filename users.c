#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "users.h"


char *makeID(User *user_instance) {

    char *id_string = malloc(sizeof(char) * 9);// 4 + 4 + 1 ('\0')
    int *random_number = malloc(sizeof(int));
    *random_number = 1 + rand() % 10000;

    // filling empty digits with Zeros e.g. 0067
    char *random_number_string = malloc(sizeof(char) * 5);
    if ((*random_number >= 1) && (*random_number <= 9)) {
        sprintf(
        random_number_string, 
        "000%d",
        *random_number
        );
    } else if ((*random_number >= 10) && (*random_number <= 99)) {
        sprintf(
        random_number_string, 
        "00%d",
        *random_number
        );
        
    } else if ((*random_number >= 100) && (*random_number <= 999)) {
        sprintf(
        random_number_string, 
        "0%d",
        *random_number
        );   
    } else if ((*random_number >= 1000) && (*random_number <= 9999)) {
        sprintf(
        random_number_string, 
        "%d",
        *random_number
        );
    };

    random_number_string[4] = '\0';
    
    char *first_4_letters = malloc(sizeof(char) * 5);// 4 + 1('\0')
    strncpy(first_4_letters, user_instance->user_name, 4);
    first_4_letters[4] = '\0';

    sprintf(
        id_string, 
        "%s%s",
        first_4_letters,
        random_number_string
    );
    
    printf("\n%s\n", id_string);
    
    
    return id_string;

};


int createUser(char *user_name, int *age, int *role, char *Path) {

    User *user_instance = malloc(sizeof(User));

    strncpy(user_instance->user_name, user_name, (MAX_USERNAME - 1));
    user_instance->user_name[MAX_USERNAME - 1] = '\0';
    user_instance->user_age = *age;
    strncpy(user_instance->user_id, (makeID(user_instance)), 8);
    user_instance->user_name[8] = '\0';

    

    int err_code = formatUser(user_instance, role, Path);

    
    free(user_instance);
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
        "%s,%s,%d,%s\n", 
        user_instance->user_id,
        user_instance->user_name, 
        user_instance->user_age, 
        role_string
    );

    int save_state = saveUser(formatted_string, Path);

    free(formatted_string);
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

