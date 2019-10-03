/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>*/


#include "../inc/header.h"


/*
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
static int mx_pow(int n);
static void iteretions(const int *arr);
void matrixPrint(int operand1, int operation, int operand2, int operand3);
int validation(char *operand1, char *operation, char *operand2,char *result, int argc, int error_code);
*/
void mx_printchar(char c) {
	write(1, &c, 1);
}


void mx_printint(int n) {
	int len = 1;
	int minus = 1;

    if (n < 0) {
		mx_printchar('-');
		minus = -1;
	}
	for (int i = n; i / 10 != 0; i /= 10)
		len *= 10;
	for (int i = len; i > 0; i /= 10) {
		mx_printchar((n / i) * minus + 48);
		n %= i;
	}
}

//----------------



int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL) return NULL;

    int *arr = malloc(4 * size);
    if (arr != NULL)
        for (int i = 0; i < size; i++)
            arr[i] = src[i];
    return arr;
}


bool mx_isdigit(int c) {
	if (c >= 48 && c <= 57)
        return true;
    else
		return false;
}

bool mx_isspace(char c) {
	if (c == 32 || (c >= 9 && c <= 13))
        return true;
    else
		return false;
}


int *mx_intnew(const int size) {
    if (size <= 0) return NULL;
    int *p = malloc(size * 4);
    if (p != NULL)
        for (int i = 0; i < size; i++)
            p[i] = -10;
    return p;
}

int mx_strlen(const char *s) {
	int i;
	
	for (i = 0; s[i] != '\0'; i++);
	return i;
}


//---------------

int *mx_atoi_arr(char *operand1, char *operation, char *operand2, char *operand3) {
    int j = 0;

    // 6 is sum of all Extra options: (sign before operand * 3) + operation + "=" + "-10 (like end of array)"
    int *arr = mx_intnew(mx_strlen(operand1) + mx_strlen(operand2) + mx_strlen(operand3) + 6);
    int *oprnd1_arr = mx_atoi_operand(operand1);
    int operation_int = mx_atoi_operation(operation);
    int *oprnd2_arr = mx_atoi_operand(operand2);
    int *oprnd3_arr = mx_atoi_operand(operand3);
    //int errors = 0;

    if (operation_int == -12) arr[0] = -12;
    else if (oprnd1_arr[0] == -11) arr[0] = -11;
    else if (oprnd2_arr[0] == -11) arr[0] = -13;
    else if (oprnd3_arr[0] == -11) arr[0] = -14;
    else {
        for (int i = 0; oprnd1_arr[i] != -10; i++) {
            arr[j] = oprnd1_arr[i];
            j++;
        }
        arr[j] = operation_int;
        j++;
        for (int i = 0; oprnd2_arr[i] != -10; i++) {
            arr[j] = oprnd2_arr[i];
            j++;
        }
        arr[j] = -8;
        j++;
        for (int i = 0; oprnd3_arr[i] != -10; i++) {
            arr[j] = oprnd3_arr[i];
            j++;
        }
        j--; // one step back to "-10"
    }
    return mx_copy_int_arr(arr, j + 2);
}

static int *mx_atoi_operand(char *operand) {
    int i = 0;
    int j = 1;
    int *arr = mx_intnew(mx_strlen(operand) + 2); // 2 = sign + "-10"
    
    arr[0] = 1; // sign
    while (mx_isspace(operand[i]))
        i++;
    if (operand[i] == '-' || operand[i] == '+') {
        if ( operand[i] == '-')
            arr[0] = -1;
        i++;
    }
    while (mx_isdigit(operand[i]) || operand[i] == '?') { 
        if (mx_isdigit(operand[i]))
            arr[j] = (operand[i] - 48);
        else
            arr[j] = 10; // 10 is "?" in our array
        i++;
        j++;
    }
    while (mx_isspace(operand[i]))
        i++;
    if (operand[i] != '\0' || j == 1) // min 1 digit
            arr[0] = -11; // error of operand
    arr[j] = -10; // end of operand
    return arr;
}

static int mx_atoi_operation(char *operation) {
    int i = 0;
    int oper_int = -12;

    while (mx_isspace(operation[i]))
        i++;
    switch(operation[i]) {
        case '-':
            oper_int = -5;
            break;
        case '+':
            oper_int = -4;
            break;
        case '*':
            oper_int = -6;
            break;
        case '/':
            oper_int = -7;
            break;
        case '?':
            oper_int = -3;
            break;
        default:
            return -12; // error of operation
            break;
    }
    i++;
    while (mx_isspace(operation[i]))
        i++;
    if (operation[i] != '\0')
            return -12; // error of operation
    return oper_int;
}

//---------------------------------

static int check_operation (const int *arr) {
    int i = 0;
    while (arr[i] > -2) 
        i++;
    return arr[i];
}

static int transfer (const int *arr) {
    int num = 0;
    int sign = arr[0];
    int i = 1;

    while (arr[i] >= 0) {
    	num *= 10;
    	num += arr[i];
    	i++;
    }
    num *= sign;
    //printf("%d ", num);
    return num;
    //printf("%d ", num);
}

static long mx_pow(int n) {
	long result = 1;
    for (int i = 0; i < n; i++) 
    	result *= 10;
    return result;
}

/*int digit_iteretions() {
​
}*/


static void iteretions(const int *arr) {
	int sign_arr[4] = {-4, -5, -6, -7};
    int len_arr = 0;
    int len_sign = 0;
    int k = 0;
    int operation = 0;
    int oper1;
    int oper2;
    int res;
    int my_result = 0;
    int res_operation = 0;
    int z = 0;

    while (arr[len_arr] != -10)
        len_arr++;
    len_arr++;

    int arr_cpy[len_arr];
    for (int i = 0; i < len_arr; i++) 
    	if (arr[i] == 10)
    		len_sign++;
    int digit_arr[len_sign];


    
    res_operation = check_operation(arr);
    for (z = 0; z < 4; z++) {
        for (int i = 0; i < len_sign; i++)
    	    digit_arr[i] = 0;
        for (long i = 0; i < mx_pow(len_sign); i++) {

            k = 0;
            for (int j = 0; j < len_arr; j++) 
                if (arr[j] == 10) {
                    arr_cpy[j] = digit_arr[k];
                    k++;
                }
                else 
                    arr_cpy[j] = arr[j];
                
        
            oper1 = transfer(arr_cpy);
            k = 0;
            while (arr_cpy[k] >= -1 && k < len_arr)
                k++;

            if (res_operation != -3)
                operation = arr_cpy[k];
            else
                operation = sign_arr[z];

            k++;

            oper2 = transfer(&arr_cpy[k]);

            if (operation == -7 && oper2 == 0)
                operation--;

            while (arr_cpy[k] >= -1 && k < len_arr)
                k++;
            
            k++;
            res = transfer(&arr_cpy[k]);
            //printf("res%d %d %d %d %d\n", oper1, operation, oper2, res , i);
            switch (operation) {
                case -4: my_result = oper1 + oper2; break;
                case -5: my_result = oper1 - oper2; break;
                case -6: my_result = oper1 * oper2; break;
                case -7: my_result = oper1 / oper2; break;
                case -8: my_result = res + 1; break;

            }
            //printf("res%d\n", operation);
            if (res == my_result) {
                matrixPrint(oper1, operation, oper2, res);
                //printf("res%d\n", operation);
            }
            //printf("res%d\n", z);
            digit_arr[len_sign - 1]++;
            k = len_sign - 1;

            while (digit_arr[k] == 10 && k > 0) {
                digit_arr[k] = 0;
                digit_arr[k - 1]++;
                k--;
            }

        }
        if (res_operation != -3)
      	    break;

    }
}



//--------------------------


void matrixPrint(int operand1, int operation, int operand2, int operand3) {
    mx_printint(operand1);
    mx_printchar(' ');
    if(operation == -4)
        mx_printchar('+');
    else if(operation == -5)
        mx_printchar('-');
    else if(operation == -6)
        mx_printchar('*');
    else if(operation == -7)
        mx_printchar('/');
    mx_printchar(' ');
    mx_printint(operand2);
    mx_printchar(' ');
    mx_printchar('=');
    mx_printchar(' ');
    mx_printint(operand3);
    mx_printchar('\n');
}

//-----------------

int validation(char *operand1, char *operation, char *operand2,char *result, int argc, int error_code){
	int errors = 0;
	/*if(argc != 5){
		write(2, "usage: ./race02 [operand1] [operation] [operand2] [result] on", mx_strlen("usage: ./race02 [operand1] [operation] [operand2] [result]"));
		write(2, "\n", 1);
	}
	
	else*/ if(error_code == -14){
		write(2, "Invalid result: ", mx_strlen("Invalid result: "));
		write(2, result, mx_strlen(result));
		write(2, "\n", 1);
		errors++;
	}else if(error_code == -11){
			errors++;
			write(2, "Invalid operand: ", mx_strlen("Invalid operand: "));
			write(2, operand1, mx_strlen(operand1));
			write(2, "\n", 1);
		}else if(error_code == -13){
			errors++;
			write(2, "Invalid operand: ", mx_strlen("Invalid operand: "));
			write(2, operand2, mx_strlen(operand2));
			write(2, "\n", 1);
	

	}else if(error_code == -12){
			errors++;
			write(2, "Invalid operation: ", mx_strlen("Invalid operation: "));
			write(2, operation, mx_strlen(operation));
			write(2, "\n", 1);
		}

	//если errors > 0 - то это значит что были ошибки.
	return errors;
    argc++;
}

//-----------



int main(int argc, char **argv) {

    if(argc != 5){
		write(2, "usage: ./race02 [operand1] [operation] [operand2] [result] on", mx_strlen("usage: ./race02 [operand1] [operation] [operand2] [result]"));
		write(2, "\n", 1);
	} else {
        int *arr = mx_atoi_arr(argv[1], argv[2], argv[3], argv[4]);
        int errors = 0;
        //char *operand1, char *operation, char *operand2,char *result, int argc, int error_code
        if (arr[0] <= -11 && arr[0] >= -15)
            errors = validation(argv[1], argv[2], argv[3], argv[4], argc, arr[0]);
        else
            iteretions(arr);

        errors++;
    }

    return 0;
}
