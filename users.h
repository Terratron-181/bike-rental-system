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


User *createUser(char *user_name, int *age, int *role);
void formatUser(User *user_instance);
void save_user(char *formatted_user, char *Path);


#endif