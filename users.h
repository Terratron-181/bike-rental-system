#ifndef USERS_H
#define USERS_H

#define MAX_USERNAME 60

typedef enum {
    ADMIN,
    USER,
} Role;


typedef struct {
    char user_name[MAX_USERNAME];
    int user_age;
    Role user_role;
} User;


int createUser(char *user_name, int *age, int *role, char *Path);
int formatUser(User *user_instance, int *role, char *Path);
int saveUser(char *formatted_user_string, char *Path);


#endif