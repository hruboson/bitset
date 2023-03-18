/**
 * @file error.h
 * @brief   Řešení IJC-DU1, příklad B)
 *          Deklarace rozhraní pro zpracování chybového hlášení
 * @author Ondřej Hruboš (xhrubo01), FIT
 * @date 04.03.2023
 */

#ifndef ERROR_H
#define ERROR_H

#define std_err_str "(%s, %s): %s\n", __FILE__, __LINE__
#define std_err_str_var "(%s, %s): %s %s\n", __FILE__, __LINE__

void warning(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif  // !ERROR_H