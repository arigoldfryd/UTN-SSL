#ifndef SCANNER_H_
#define SCANNER_H_

#include <stdio.h>

enum {  FDT, SEP, CAD };

int get_token(char *buffer);

#endif