
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct User {
    char password[20];
    char lastName[20];
    char email[50];
    char firstName[20];
    union {
        bool active;
        int flag;
    };
};

void registerUser(struct User* user) {
    printf("Registration:\n");
    printf("First Name: ");
    scanf("%s", user->firstName);
    printf("Last Name: ");
    scanf("%s", user->lastName);
    printf("Email: ");
    scanf("%s", user->email);
    printf("Password: ");
    scanf("%s", user->password);
    user->active = true;
    printf("\nRegistration successful!\n\n");
}

void loginUser(struct User* user) {
    char email[50];
    char password[20];

    printf("Login:\n");
    printf("Email: ");
    scanf("%s", email);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(email, user->email) == 0 && strcmp(password, user->password) == 0) {
        if (user->active)
            printf("\nYou are authenticated. Welcome, %s!\n\n", user->firstName);
        else
            printf("\nYou are disabled and cannot enter the system.\n\n");
    } else {
        printf("\nAuthentication failed. You are not registered.\n\n");
    }
}

int main() {
    struct User user1, user2;

    registerUser(&user1);
    registerUser(&user2);

    loginUser(&user1);
    loginUser(&user2);

    return 0;}