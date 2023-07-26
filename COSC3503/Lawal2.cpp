///////////////////////////////////////////////////////////////////
// Student Name: Dayo Lawal
// Course: COSC 3503 - Operating Systems
// Assignment: #2 - HTML Tag Detection
// Source Code File Name: Lawal2
// Program's Purpose: Parse an html file for every html tag
// Program's Limitations: None known
// Development Computer: Dayo's PC
// Operating System: Windows 10
// Compiler: Gnu g++
// Program's Operational Status: Fully Operational
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int parse(string line) {
    bool tag_found = false;
    int tags = 0;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '<') {
            tag_found = true;
            tags++;
        }
        if (tag_found) {
            cout << line[i];
            if (line[i] == '>') {
                tag_found = false;
                cout << '\n';
            } 
        }
    }

    return tags;
}

int main(int argc, char *argv[]) {
    cout <<  "*** START OF HTML TAGS ***\n" << endl;

    ifstream file;
    string line;
    int tags;

    file.open(argv[1]);

    while(getline(file, line))
    {
        tags += parse(line);
    }

    string tag_amount = to_string(tags);

    cout << "\nTOTAL NUMBER OF HTML TAGS FOUND: " + tag_amount;

    return 0;
}