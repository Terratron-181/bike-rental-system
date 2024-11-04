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
    // So, First 4 letters + a random 4 digits number
    // 4 + 4 = 8 characters. + 1 character for '\0' = 9 chars.
    char user_id[9];
} User;


int createUser(char *user_name, int *age, int *role, char *Path);
char *makeID(User *user_instance);
int formatUser(User *user_instance, int *role, char *Path);
int saveUser(char *formatted_user_string, char *Path);


#endif