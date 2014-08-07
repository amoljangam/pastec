#ifndef MESSAGES_H
#define MESSAGES_H

#include <sys/types.h>
#include <string>

using namespace std;


enum Queries
{
    INDEX_IMAGE =                       0x00010000,
    SEARCH =                            0x00020000,
    PING =                              0x00030000,
    WRITE_INDEX =                       0x00040000,
    CLEAR_INDEX =                       0x00050000,
    REMOVE_IMAGE =                      0x00060000
};

enum Replies
{
    OK =                                0x10010000,
    ERROR_GENERIC =                     0x10020000,
    PONG =                              0x10030000,
    TOO_MANY_CLIENTS =                  0x10040000,

    IMAGE_DATA_TOO_BIG =                0x10050100,
    IMAGE_NOT_INDEXED =                 0x10050200,
    IMAGE_SIZE_TOO_BIG =                0x10050300,
    IMAGE_NOT_DECODED =                 0x10050400,
    IMAGE_SIZE_TOO_SMALL =              0x10050500,
    IMAGE_ALREADY_IN_INDEX =            0x10050600,
    IMAGE_NOT_FOUND =                   0x10050700,

    INDEX_LOADED =                      0x10060100,
    INDEX_NOT_FOUND =                   0x10060200,
    INDEX_WRITTEN =                     0x10060300,
    INDEX_NOT_WRITTEN =                 0x10060400,
    INDEX_CLEARED =                     0x10060500,
};


class Converter
{
public:
    /**
     * @brief Convert a return code to a string
     * @param r the code.
     * @return the code converted to a string.
     */
    static string codeToString(u_int32_t r)
    {
        string s;
        switch (r)
        {
            case OK: s = "OK"; break;
            case ERROR_GENERIC: s = "ERROR_GENERIC"; break;
            case PONG: s = "PONG"; break;
            case TOO_MANY_CLIENTS: s = "TOO_MANY_CLIENTS"; break;

            case IMAGE_DATA_TOO_BIG: s = "IMAGE_DATA_TOO_BIG"; break;
            case IMAGE_NOT_INDEXED: s = "IMAGE_NOT_INDEXED"; break;
            case IMAGE_SIZE_TOO_BIG: s = "IMAGE_SIZE_TOO_BIG"; break;
            case IMAGE_NOT_DECODED: s = "IMAGE_NOT_DECODED"; break;
            case IMAGE_SIZE_TOO_SMALL: s = "IMAGE_SIZE_TOO_SMALL"; break;
            case IMAGE_ALREADY_IN_INDEX: s = "IMAGE_ALREADY_IN_INDEX"; break;
            case IMAGE_NOT_FOUND: s = "IMAGE_NOT_FOUND"; break;

            case INDEX_LOADED: s = "INDEX_LOADED"; break;
            case INDEX_NOT_FOUND: s = "INDEX_NOT_FOUND"; break;
            case INDEX_WRITTEN: s = "INDEX_WRITTEN"; break;
            case INDEX_NOT_WRITTEN: s = "INDEX_NOT_WRITTEN"; break;
            case INDEX_CLEARED: s = "INDEX_CLEARED"; break;
            default: break;
        }
        return s;
    }
};

#define MSG_INDEX_IMAGE_HEADER_LEN 12
#define MSG_REMOVE_IMAGE_LEN 8


#endif // MESSAGES_H
