///////////////////////////////////////////////////////////////////
// Student name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #3 - Purposes of HTML Tags
// Source Code File name: Lawal3.c
// Program's Purpose: Finds and prints a list of the HTML tags found in
//                    a file and the purpose of certain tags
// Program's Limitations: Assumes that the input file is a
//                        properly-formatted HTML file
// Development Computer: Dayo's Computer
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fully Operational
/////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define TRUE  1
#define FALSE 0
#define LEFT_ANGLE_BRACKET '<'
#define RIGHT_ANGLE_BRACKET '>'
#define SPACE ' '
#define MAX_LENGTH 100


// Function Prototypes
int detectTags(char* file_name);
void displayPurpose(char *tag);


// #############################################################
int main(int argc, char *argv[])
{
int tagCount;

printf("\n*** START OF HTML TAGS ***\n\n");

tagCount = detectTags(argv[1]);

printf("\nTOTAL NUMBER OF HTML TAGS FOUND: %d \n", tagCount);

return 0;
} // End main


// #############################################################
int detectTags(char* file_name)
{
    FILE* file;
    char ch;
    char str[MAX_LENGTH];
    int tagCount = 0;
    int tag_found = FALSE;
    int pos = 0;

    file = fopen(file_name, "r");
    if(file == NULL) {
        perror("Error in opening file.");
        return(-1);
    }


    while (1) {
        ch = fgetc(file);
        if (feof(file)) {
            break;
        }
        
        if (ch == LEFT_ANGLE_BRACKET) {
            tag_found = TRUE;
            tagCount++;
        }
        

        if (tag_found) {
            str[pos] = ch;
            pos++;
        }

        if (ch == RIGHT_ANGLE_BRACKET) {
            str[pos+1] = '\0';
            displayPurpose(str);
            tag_found = FALSE;
            pos = 0;
            memset(str,0,strlen(str));
        }

    }

    fclose(file);

    return tagCount;

} // End detectTags


// #############################################################
void displayPurpose(char *tag)
{
    for (int i = 1; i < strlen(tag) - 1; i++) {
        tag[i] = toupper(tag[i]);
    }

    if (strncmp(tag, "<HTML>", MAX_LENGTH) == 0) {
        printf("%-100s: Start of HTML file\n", tag);
    } else if (strncmp(tag, "</HTML>", MAX_LENGTH) == 0) {
        printf("%-100s: End of HTML file\n", tag);
    } else if (strncmp(tag, "<HEAD>", MAX_LENGTH) == 0) {
        printf("%-100s: Start of HTML header\n", tag);
    } else if (strncmp(tag, "</HEAD>", MAX_LENGTH) == 0) {
        printf("%-100s: End of HTML header\n", tag);
    } else if (strncmp(tag, "<TITLE>", MAX_LENGTH) == 0) {
        printf("%-100s: Start of document title\n", tag);
    } else if (strncmp(tag, "</TITLE>", MAX_LENGTH) == 0) {
        printf("%-100s: End of document title\n", tag);
    } else if (strncmp(tag, "<B>", MAX_LENGTH) == 0) {
        printf("%-100s: Start of bold font\n", tag);
    } else if (strncmp(tag, "</B>", MAX_LENGTH) == 0) {
        printf("%-100s: End of bold font\n", tag);
    } else if (strncmp(tag, "<I>", MAX_LENGTH) == 0) {
        printf("%-100s: Start of italic font\n", tag);
    } else if (strncmp(tag, "</I>", MAX_LENGTH) == 0) {
        printf("%-100s: End of italic font\n", tag);
    } else {
        printf("%-100s: Unknown HTML tag\n", tag);
    }
} // End displayPurpose
