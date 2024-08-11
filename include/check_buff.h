#ifndef CHECK_BUFF
#define CHECK_BUFF

#include <stdbool.h>
#include <string.h>

bool check_buff(char *buff) {
    if ( buff[0] == '\0' ) {
        return false;
    }
    return true;
}

#endif
