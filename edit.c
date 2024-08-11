#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "include/read_file.h"
#include "include/check_buff.h"
#include "include/check_mode.h"
#include "include/kbhit.h"

#define NORMAL 27
#define COMMAND 58
#define INSERT 105
#define CMD_MAX 128

int main(int argc, char **argv) {
    if ( argc < 2 ) {
        // not file
        printf("please input file");
        exit(-1);
    }
    init_keyboard();
    system("clear");
    FILE *fp;
    int mode = NORMAL;  // default mode
    char buffer[KB];  // 1 KB buffer
    memset(buffer, 0, sizeof(buffer));  // clear buff

    fp = fopen(argv[1], "a+");

    int ch = 0;  // get a char of stdin
    int i = 0;
    bool lctrl = true; // control loop
    while ( lctrl ) {

        system("clear");
        printf("%s\n", argv[1]);  // output file name
        printf("%s\n", check_mode(mode));  // output mode info
        read_file(fp, buffer);
        fflush(stdout);

        // get keyboard
        while ( !kbhit() );
        ch = readch();

        //  change mode
        if ( ch == ESC && ( mode == COMMAND || mode == INSERT ) ) {
            mode = NORMAL;
        }
        else if ( ch == 58 && mode == NORMAL ) {
            mode = COMMAND;
        }
        else if ( ch == 105 && mode == NORMAL ) {
            mode = INSERT;
        }

        // mode process
        if ( mode == COMMAND ) {
            close_keyboard();
            fflush(stdout);
            int j = 0;
            char cmd[CMD_MAX];
            memset(cmd, 0, sizeof(cmd));

            printf("\n\n\n\n\n\n\n\n\n\n\n:");
            scanf("%s", cmd);
            /*
            if ( strcmp(cmd, "wq") == 0 ) {
                fprintf(fp, "%s", buff);
                memset(buff, 0, sizeof(buff));
                break;
            }
            */
            switch (cmd[j++]) {
                case 'w' :
                    fprintf(fp, "%s", buffer);
                    memset(buffer, 0, sizeof(buffer));
                case 'q' :
                    lctrl = false;
            }

        }
        else if ( mode == INSERT ) {
            close_keyboard();
            buffer[i++] = ch;
        }
        else if ( mode == NORMAL ) {
            init_keyboard();
        }

    }

    close_keyboard();
    fclose(fp);
    return 0;
}

