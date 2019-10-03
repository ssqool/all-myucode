#include <unistd.h>

void mx_printint(int n){
    int m = 1;
    char g[11];
    if(n==0)
        mx_printchar(n);
    if(n<0)
        m=-1;
    for(int i = 0; n != 0; i++){
        g[i] = (n % 10 * m) + 48;
        n = n / 10;
    }
}



int main(){
mx_printint(-2147483648); 
}