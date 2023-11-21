#include "main.h"

/*
* argv[0] - имя файла с бинарными данными
* вывод - количество корректно разобранных пакетов
*/


#if 1
int main(int argc, char **argv) {

    if (argv[1] == 0) {
        argv[1] = "Source/test.bin";
    }

    Parser parser;
    std::vector<Message> massage;
    std::ifstream readable_file;

    FileState state = open_file(argv, readable_file);

    if (state == FileState::FILE_OPEN_ERROR) {
        return 0;
    }

    size_t file_byte_size = 0;

    readable_file.seekg(0, std::ios_base::end); /* get file size in bytes */

    file_byte_size = readable_file.tellg();

    char* buffer = new char(file_byte_size);
    uint32_t ch;
    int i = 0;

    readable_file.seekg(0);

    while (!readable_file.eof()) {
        readable_file.read((char*)&ch, sizeof(uint8_t));
        std::cout << ch << " " << std::hex << ch << std::endl;
        buffer[i] = ch;
        std::cout << buffer[i++] << std::endl;
    }

    massage = parser.add(buffer, file_byte_size);

    delete[] buffer;

    readable_file.close();

    return 0;
}
#endif

/*
* 	@bref: read data from file
*	@param (data) - array for storage data
*	@param (inFile) - opaned file struct
*/
void read_data(char* data, std::ifstream* inFile) {
    uint32_t ch;
    int i = 0;

    while (!inFile->eof()) {
        inFile->read((char*)&ch, sizeof(uint8_t));
        std::cout << ch << " " << std::hex << ch << std::endl;
        data[i++] = ch;
    }
}


/*
* 	@bref: function open binary file for reading
*	@param (argv) - parameter from console
*	@param (inFile) - opaned file struct
*/
FileState open_file(char** argv, std::ifstream& inFile) {

    /* Open readable file */
    char* file_name;

    if (argv[1] != 0x0) {
        inFile.open(argv[1], std::ios_base::binary);
        file_name = (char*)argv[1];

    } else {
        printf(" Enter file name!\n");
        return FileState::FILE_OPEN_ERROR;
    }

    if (!inFile.is_open()) {
        printf("\n %s couldn't open\n", file_name);
        return FileState::FILE_OPEN_ERROR;
    }

    std::cout << " READABLE FILE: " << file_name << std::endl;

    return FileState::FILE_OPEN_SUCCESS;
}
