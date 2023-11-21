#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <cstring>

#define DEFENITION_SIZE				   ( 4 )
#define CRC_SIZE
#define MAX_DATA_SIZE                  ( 255 )
#define MAX_DATA_SIZE_EXPAND           ( 65536 )
#define MAX_PACK_SIZE				   (DEFENITION_SIZE + MAX_DATA_SIZE_EXPAND + CRC_SIZE)
#define HEADER						   ( 0xAABB )

enum class CRC_16_State {
    CRC_CHECK_SUCCESS,
	CRC_CHECK_ERROR,
};

typedef struct DataPack {
    uint16_t header;
    uint8_t id;

    uint8_t size;

    uint8_t data[MAX_DATA_SIZE];

    uint16_t crc;
} t_data_pack;

typedef struct DataPackExpand {
    uint16_t header;
    uint8_t id;

    uint8_t expand_flag;

    uint16_t size;

    uint8_t data[MAX_DATA_SIZE_EXPAND];

    uint16_t crc;
} t_data_pack_expnd;

struct Message {
    int id;
    std::string data;
};

class Parser {
private:
	union {
		t_data_pack* dp;
		t_data_pack_expnd* dp_expnd;
		const char* tmp_arr;
	}t_union_pack;

	char definit[DEFENITION_SIZE];

public:
    Parser();
    std::vector<Message> add(const char* data, size_t size);
	CRC_16_State CRC_16(const char *pcBlock, unsigned short len, const uint16_t crc_transm);
};

#endif // !PARSER_H
