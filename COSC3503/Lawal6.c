///////////////////////////////////////////////////////////////////
// Student name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #6 - Multiple Processes
// Source Code File name: Lawal5.c
// Program's Purpose: Provides the functionality that searches the list for the
//          maximum integer value with the help of 1 or more child
//          processes
// Program's Limitations: Because a child process can only return a value up
//       to 255, the largest possible integer in the list cannot exceed 255
// Development Computer: Dayo's Computer
// Operating System: Windows 10
// Compiler: Gnu g++
// Build Instructions: See the driver module
// Program's Operational Status: Fully Operational
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "listSearcher.h"

// Function Prototypes
static int findMaxInteger(int list[], int startingIndex, int numbrOfEntries);


// ################################################################
void searchIntegerList(int list[], int nbrOfListEntries, int childrenCount)
{
    int entry_count = nbrOfListEntries / childrenCount;
    int last_child_count = nbrOfListEntries % childrenCount;
    int last_child = childrenCount - 1;

    for (int i = 0; i < childrenCount; i++) {
        pid_t pid = fork();
        int cur_index = i * entry_count;
        if (pid == -1) {
            error("Fork failed");
            exit(1);
        } else if (pid == 0) {
            if (i == last_child) {
                int max = findMaxInteger(list, cur_index, last_child_count);
                sleep(2);
                exit(max);
            } else {
                int max = findMaxInteger(list, cur_index, entry_count);
                sleep(2);
                exit(max);
            }
        } else {
            continue;
        }
    }
} // End searchIntegerList


// ################################################################
static int findMaxInteger(int list[], int startingIndex, int nbrOfEntries)
{
    int max = 0;
    int final_index = startingIndex + nbrOfEntries - 1;
    printf("(Child process #%d) Searching indexes %d through %d ...", getpid(), startingIndex, final_index);
    for (int i = startingIndex; i <= final_index; i++) {
        if (list[i] > max) {
            max = list[i];
        }
    }
    return max;
} // End findMaxInteger


