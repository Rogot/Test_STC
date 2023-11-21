#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h> /* File Control Definition */
#include <errno.h> /* ERROR Terminal Control Definition */
#include <termios.h> /* POSIX Terminal Control Definition */
#include <unistd.h> /* UNIX Control Definition */

#include <fstream>
#include <iostream>

#include "../Parser/inc/Parser.h"

enum class FileState {
    FILE_OPEN_SUCCESS,
    FILE_OPEN_ERROR,
};

FileState open_file(char** argv, std::ifstream& inFile);
void read_data(char* data, std::ifstream* inFile);

#endif // !MAIN_H

/*
 char buffer[200];
    uint32_t ch;
    int i = 0;
    while (!readable_file.eof()) {
        readable_file.read((char*)&ch, sizeof(uint8_t));
        std::cout << ch << " " << std::hex << ch << std::endl;
        //buffer[i++] = ch;
    }
*/
