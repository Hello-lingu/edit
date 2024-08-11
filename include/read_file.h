#ifndef READ_FILE
#define READ_FILE

#include <stdio.h>

#ifndef KB
    #define KB 1024
#endif

void read_file(FILE *fp, char *buff) {
    char file_content[KB];
    int line_number = 0;
    fseek(fp, 0, SEEK_SET);
    while ( true ) {
        printf("%d\t", ++line_number);
        fgets(file_content, KB, fp);
        if ( feof(fp) ) {
            break;
        }
        printf("%s", file_content);
    }

    int i = 0;
    while ( buff[i++] != '\0' ) {
        printf("%d\t", ++line_number);
        while ( buff[i] != '\0' ) {
            printf("%c", buff[i++]);
            if ( buff[i] == '\n' ) {
                printf("\n");
                break;
            }
        }
    }
}

#endif

