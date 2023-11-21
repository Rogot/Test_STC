#include "../Parser/inc/Parser.h"

Parser::Parser() {

}


/*
* 	@bref: parses the read data
*	@param (data) - array of processing data
*	@param (size) - size of data
*/
std::vector<Message> Parser::add(const char* data, size_t size) {

	std::vector<Message> res_packs;
	Message tmp;
	/* "Запасной" вариант */
	unsigned long pack_cnt = 0;
	/*********************/

	CRC_16_State crc_state;
	unsigned long long int pointer_offset = 0;
	unsigned long long int global_pointer_offset = 0;

	//bool is_error = 1;  /* identify mistakes in packages */


    t_union_pack.tmp_arr = data;

	std::cout << "\n NEW DATA: \n";

	for (unsigned int i = 0; i < size; i += pointer_offset) {

		t_union_pack.tmp_arr += pointer_offset;
		global_pointer_offset += pointer_offset;
		pointer_offset = 0;


		if (t_union_pack.dp->header == HEADER) { /* check correct header */
			tmp.id = t_union_pack.dp->id;		 /* write message ID */
			pointer_offset += 3;				 /* header (2 bytes) + id (1 byte)  */

			unsigned int data_size;

			/* identify byte count data in package */
			if (t_union_pack.dp_expnd->expand_flag == 0xFF) {
				pointer_offset += 2; /* size (2 byte)*/

				data_size = t_union_pack.dp_expnd->size;
				pointer_offset++; /* flag (1 byte) */
			} else {
				pointer_offset++; /* size (1 byte)*/

				data_size = t_union_pack.dp->size;
			}

			pointer_offset += data_size;

			for (unsigned int j = 0; j < data_size; j++) {
				std::cout << t_union_pack.dp->data[j] << std::endl;

				tmp.data.push_back(t_union_pack.dp->data[j]);
			}

			/* calculate CRC-16 */

			uint16_t crc = t_union_pack.tmp_arr[pointer_offset + 1] << 8;
			crc |= t_union_pack.tmp_arr[pointer_offset] & 0xFF;

			crc_state = CRC_16(t_union_pack.tmp_arr, pointer_offset, crc);

			pointer_offset += 2; /* crc (2 bytes) */

			if (crc_state == CRC_16_State::CRC_CHECK_SUCCESS) {

				/*
				 * !!! не понял почему выскакивает ошибка
				 *  при выполнении программы,
				 *  но элемент не добавляется !!!
				 *  Проверял в main() - все работало
				 */

				//res_packs.push_back(tmp);
				//std::cout << "Count packages: " << res_packs.size() << std::endl;

				/* "Запасной" вариант */
				pack_cnt++;
				std::cout << "Count packages: " << pack_cnt << std::endl;
				/*********************/

				std::cout << "ID package: " << tmp.id << std::endl;
			}

		} else {	/* search header of package or end of array */
			while (t_union_pack.dp->header == HEADER || global_pointer_offset < size) {
				global_pointer_offset++;
				t_union_pack.tmp_arr++;
			}
		}
	}

	return res_packs;

}

/*
* 	@bref: calc CRC-16-CCITT
*	@param (data) - array of packege
*	@param (len) - size of data
*	@param (crc_transm) - crc as part of packege
*/
CRC_16_State Parser::CRC_16(const char *pcBlock, unsigned short len,
		const uint16_t crc_transm) {
	unsigned short crc = 0xFFFF;
	unsigned char i;

	while (len--) {
		crc ^= *pcBlock++ << 8;

		for (i = 0; i < 8; i++)
			crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
	}

	if (crc == crc_transm) {
		return CRC_16_State::CRC_CHECK_SUCCESS;
	} else {
		return CRC_16_State::CRC_CHECK_ERROR;
	}
}

