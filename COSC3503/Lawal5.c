///////////////////////////////////////////////////////////////////
// Student name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #5 - Environment Variables
// Source Code File name: Lawal5.c
// Program's Purpose: Displays a given environment variable or all
//                    existing enviornment variables
// Program's Limitations: None known
// Development Computer: Dayo's Computer
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fully Operational
/////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

// Function Prototypes
void exit_handler();

int main(int argc, char *argv[]) {

    if (atexit(exit_handler))
    {
        fprintf(stderr, "Failed to run exit handler\n");
        exit(1);
    }

    char str[] = "-a";

    if (argc > 2) {
        fprintf(stderr, "Usage:\na.out\na.out <environment_variable_name>\na.out -a\n");
        return -1;
    } else if (argc == 1) {
        printf("Enter the name of an environment variable: ");

        char* var_name;
        scanf("%s", var_name);
        
        if (getenv(var_name)) {
            printf("%s : %s\n", var_name, getenv(var_name));
        } else {
            fprintf(stderr, "%s is not an existing environment variable name\n", var_name);
        }
        
    } else if (!strcmp(argv[1], str)) {
        for (int i = 0; environ[i] != NULL; i++) {
            printf("%s\n", environ[i]);
        }
    } else {
        if (getenv(argv[1])) {
            printf("%s : %s\n", argv[1], getenv(argv[1]));
        } else {
            fprintf(stderr, "%s is not an existing environment variable name\n", argv[1]);
        }
    }

    
    return 0;
}

void exit_handler() {
    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * *\nEnvironment Variable Display Program (by Dayo Lawal)");
}