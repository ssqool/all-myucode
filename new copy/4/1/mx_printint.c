#include "mx_printchar.c"

void mx_printint(int n){
    char s[11];
    int res = 0;
    int i;
    int j;
    int m = 1;
    
    if(n == 0)
        mx_printchar(48);
    if(n < 0)
        m = -1;
    for(i = 0; n != 0 ; i++){
        s[i] = (n % 10 * m) + '0';
        n = n / 10;
    }
    if(m == -1){
        s[i] = '-';
        j = i;
    }
    else
        j = i-1;
    for(int k = j; k != -1; k--){
          mx_printchar(s[k]);     
    } 
}
