#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
int mx_atoi(const char *str);

int mx_atoi(const char *str) {
    int value = 0;
    int sign = 1;
    int count = 0;

    for(int i = 0; str[i]; i++){
        if(mx_isspace(str[i])){
            count++;
            printf("%d\n",count);
        }
        else if(! mx_isspace(str[i])){
            break;
        }
    }
    if( str[count] == '+' || str[count] == '-' ) {
        if( str[count] == '-' ) sign = - 1;
        str++;
    }
    for(int i = count; mx_isdigit(str[i]); i++){
        value *= 10;
        value += (int) (str[i] - '0');
        str++;
    }
    return value * sign;
}

