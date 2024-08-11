#ifndef CHECK_MODE
#define CHECK_MODE

#ifndef VIRTUAL
    #define NORMAL 27
#endif

#ifndef COMMAND
    #define COMMAND 58
#endif

#ifndef INSERT
    #define INSERT 105
#endif

#ifndef ESC
    #define ESC 27
#endif

char *check_mode(int mode) {
    if ( mode == NORMAL ) {
        return "VIRTUAL";
    }
    else if ( mode == COMMAND ) {
        return "COMMAND";
    }
    else if ( mode == INSERT ) {
        return "INSERT";
    }
    return NULL;
}

#endif
