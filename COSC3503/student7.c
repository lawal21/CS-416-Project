///////////////////////////////////////////////////////////////////
// Student name: 
// Course: COSC 3503 - Operating Systems
// Assignment: #7 - Unbuffered Input and Output
// Source Code File name: Lawal7.c
// Program's Purpose: Removes all of the single-line comments from a C, C++, or
//    Java text file and produces an output file with "nc" appended to the front
//    of the file name.  The program obtains the option "-s" or "-p" from the
//    command line followed by one or more file names. Each file on the 
//    command line is processed by the program either sequentially or in
//    parallel.  For the parallel approach, a separate forked process
//    performs the comment removal steps and a single parent process waits
//    for all children to complete  
// Program's Limitations: It assumes the input files are text files and that the 
//    operating system allows a program to have as many child processes
//    running as the number of files entered on the command line 
// Development Computer: Dayo's Computer
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fulfills all requirements
///////////////////////////////////////////////////////////////////

#include "commentRemover.h"

#define GENERAL_BUFFER_SIZE 100
#define WRITE_BUFFER_SIZE 1
#define SLASH '/'
#define NEW_LINE '\n'
#define FALSE 0
#define TRUE  1

// Function Prototypes
static void processInputFile(const char *inputFileName);
static void removeComments(int inputFile, int outputFile);


// ################################################################
void performSequentialProcessing(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        processInputFile(argv[i]);
    }

} // End performSequentialProcessing


// ################################################################
void performParallelProcessing(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
    }

} // End performParallelProcessing


// ################################################################
static void processInputFile(const char *inputFileName)
{


} // End processInputFile


// ################################################################
static void removeComments(int inputFile, int outputFile)
{



} // End removeComments
