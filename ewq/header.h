#ifndef _header_H_
#define _header_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mx_printchar(char c);
void mx_printint(int n);
int *mx_copy_int_arr(const int *src, int size);
bool mx_isdigit(int c);
bool mx_isspace(char c);
int *mx_intnew(const int size);
int mx_strlen(const char *s);
int *mx_atoi_arr(char *operand1, char *operation, char *operand2, char *operand3);
static int *mx_atoi_operand(char *operand);
static int mx_atoi_operation(char *operation);
static int check_operation (const int *arr);
static int transfer (const int *arr);
static long mx_pow(int n);
static void iteretions(const int *arr);
void matrixPrint(int operand1, int operation, int operand2, int operand3);
int validation(char *operand1, char *operation, char *operand2,char *result, int argc, int error_code);

#endif
