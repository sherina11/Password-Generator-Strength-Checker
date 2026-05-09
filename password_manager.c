#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Colors
#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// Functions
void line() {
    printf(BLUE "+--------------------------------------+\n" RESET);
}

void title(char text[]) {
    line();
    printf(BLUE "| %-36s |\n" RESET, text);
    line();
}

void pauseScreen() {
    printf(YELLOW "\nPress Enter to continue..." RESET);
    getchar();
    getchar();
}

// Password Generator
void generatePassword() {

    char chars[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789@#$%&*";

    int length;
    char password[100];

    printf("\n Enter password length: ");
    scanf("%d", &length);

    srand(time(0));

    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(chars);
        password[i] = chars[index];
    }

    password[length] = '\0';

    printf(GREEN "\n Generated Password: %s\n" RESET, password);
}

// Password Strength Checker
void checkStrength() {

    char password[100];
    int upper = 0, lower = 0, digit = 0, special = 0;

    printf("\n Enter password to check: ");
    scanf("%s", password);

    for (int i = 0; i < strlen(password); i++) {

        if (isupper(password[i]))
            upper++;

        else if (islower(password[i]))
            lower++;

        else if (isdigit(password[i]))
            digit++;

        else
            special++;
    }

    printf("\n");

    if (strlen(password) >= 8 &&
        upper > 0 &&
        lower > 0 &&
        digit > 0 &&
        special > 0) {

        printf(GREEN " ✔ Strong Password\n" RESET);

    } else {

        printf(RED " ✘ Weak Password\n" RESET);
    }
}

// Main
int main() {

    int choice;

    while (1) {

        system("cls || clear");

        title("PASSWORD GENERATOR SYSTEM");

        printf(YELLOW " 1. Generate Password\n" RESET);
        printf(YELLOW " 2. Check Password Strength\n" RESET);
        printf(YELLOW " 3. Exit\n" RESET);

        line();

        printf(CYAN " Enter your choice: " RESET);
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                generatePassword();
                pauseScreen();
                break;

            case 2:
                checkStrength();
                pauseScreen();
                break;

            case 3:
                printf(GREEN "\n Thank You!\n" RESET);
                exit(0);

            default:
                printf(RED "\n Invalid Choice!\n" RESET);
                pauseScreen();
        }
    }

    return 0;
}