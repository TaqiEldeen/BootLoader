#ifndef PARSER_H
#define PARSER_H

#define RECORD_TYPE_INDEX    8

typedef enum {
	END_OF_FILE_RECORD,
	EXTENDED_SEGMENT_ADDRESS_RECORD,
	START_SEGMENT_ADDRESS_RECORD,
	EXTENDED_LINEAR_ADDRESS_RECORD,
	START_LINEAR_ADDRESS_RECORD,
	DATA_RECORD,
    DEFAULT,
	CHECK_SUM_ERROR
}HEX_RECORD_TYPE;

typedef enum {
	NO_ERR,
	ERR
}CHECK_SUM_t;

HEX_RECORD_TYPE Parser_eParseRecord(u8* Copy_u8BufData);

#endif // PARSER_H
