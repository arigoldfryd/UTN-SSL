#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

int size = 0;

void end_buffer(char *buffer) {
    buffer[size++] = '\0';
    size = 0;
}

int get_token(char *buffer) {
    char ch;
    
    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            if (size) {
                end_buffer(buffer);
                return CAD;
            }

            continue;
        } else if (ch == ',') {
            if (size) {
                ungetc(ch, stdin);
                end_buffer(buffer);
                return CAD;
            }

            buffer[0] = ch;
            buffer[1] = '\0';
            
            return SEP;
        } else {
            buffer[size++] = ch;
        }
    }
    
    return FDT;
}