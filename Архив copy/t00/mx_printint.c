
void mx_printchar(char c);

void mx_printint(int n);

void mx_printint(int n){
    int len = 0;
    char str[len];
    int arr_index = 0;
    for(int i = n; i > 0; i /= 10){
      len ++;
    }
    for(int i = n; i > 0; i /= 10){
      arr_index++;
      str[arr_index] = (i % 10) + '0';
    }
    for(int i = len; i > 0; i--){
      mx_printchar(str[i]);
    }
    mx_printchar('\n');
}

