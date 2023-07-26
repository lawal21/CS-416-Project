///////////////////////////////////////////////////////////////////
// Student name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #4 - Parsing Values from HTML files
// Source Code File name: Lawal4.c
// Program's Purpose: Prints the sum, average, and max value of
//                    each row in a table from a text file
// Program's Limitations: Assumes HTML file is formatted such that
//                        it has two integer values followed by
//                        a table of non-negative integer values
//                        less than 99
// Development Computer: Dayo's Computer
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fully Operational
/////////////////////////////////////////////////////////////////// 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

// Function Prototypes
int readTableSize(FILE *inputFile, int *rowCountPtr, int *colCountPtr);
void processTableContents(FILE *inputFile, int rowCount, int columnCount);
void writeReportHeading(void);
void readTableRow(FILE *inputFile, int nbrOfEntries, int rowEntries[]);
void writeReportRow(int rowNbr, int nbrOfEntries, int rowEntries[]);

int main(int argc, char *argv[]) {

    FILE* file;
    if (argc == 2) {
        file = fopen(argv[1], "r");
        if(file == NULL) {
            fprintf(stderr, "Error: Cannot open the file\n");
            return(-1);
        }
    } else {
        fprintf(stderr, "Usage: a.out [file name]\n");
        return -1;
    }

    int* rowCountPtr = (int*) malloc(sizeof(int*));;
    int* colCountPtr = (int*) malloc(sizeof(int*));;

    int tableSize = readTableSize(file, rowCountPtr, rowCountPtr);
    if (tableSize == FALSE) {
        fprintf(stderr, "Error: Row and/or column values are out of range\n");
    } else {
        processTableContents(file, *rowCountPtr, *rowCountPtr);
    }
    
    fclose(file);
    return 0;

    free(rowCountPtr);
    free(colCountPtr);
}

int readTableSize(FILE *inputFile, int *rowCountPtr, int *colCountPtr) {
    fscanf(inputFile, "%d %d\n", rowCountPtr, colCountPtr);
    if (*rowCountPtr >= 1 && *rowCountPtr <= 7 && *colCountPtr >= 2 && *colCountPtr <= 10) {
        return TRUE;
    } else {
        return FALSE;
    }
    
}

void processTableContents(FILE *inputFile, int rowCount, int columnCount) {
    writeReportHeading();
    for (int i = 0; i < rowCount; i++) {
        int rowEntries[10];
        readTableRow(inputFile, columnCount, rowEntries);
        writeReportRow(i+1, columnCount, rowEntries);
    }
}

void writeReportHeading(void) {
    printf("Row   Sum   Avg   Max\n");
    printf("---   ---   ---   ---");
}

void readTableRow(FILE *inputFile, int nbrOfEntries, int rowEntries[]) {
    for (int i = 0; i < nbrOfEntries; i++) {
        fscanf(inputFile, "%d", &rowEntries[i]);
    }
}

void writeReportRow(int rowNbr, int nbrOfEntries, int rowEntries[]) {
    printf("\n%-6d", rowNbr);
    int sum = 0;
    int max = 0;
    for (int i = 0; i < nbrOfEntries; i++) {
        if (rowEntries[i] > max) {
            max = rowEntries[i];
        }
        sum += rowEntries[i];
    }
    double avg = (double) sum / (double) nbrOfEntries;
    avg *= 10;
    round(avg);
    avg /= 10;
    printf("%-6d%-6.1f%-6d", sum, avg, max);
}
