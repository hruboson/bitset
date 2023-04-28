/**
 * @file error.c
 * @brief   Řešení IJC-DU1, příklad B)
 *          Definice rozhraní pro zpracování chybového hlášení
 * @author Ondřej Hruboš (xhrubo01), FIT
 * @date 04.03.2023
 */

#include "error.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void warning(const char *fmt, ...){
    fprintf(stderr, "Warning: ");

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

void error_exit(const char *fmt, ...) {
    fprintf(stderr, "Error: ");

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);

    exit(EXIT_FAILURE);
}