#ifndef CFILE_H
#define CFILE_H

#include <cstudio>
#include <cstdlib>


class CFile{


    //constructor or static member function. opens a text file


    // Uses RAII -> cleans up itself: eli huolehdi, että file suljetaan 

    // Function to read in the next line of the text file

    // Optional: function to print the file size

    public:

    CFile();
    CFile(const char *filename);



    private:
    // pointer to file
    FILE* file;


};

#endif