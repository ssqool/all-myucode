int mx_sqrt(int x);

int mx_sqrt(int x){
    if (x == 0 || x == 1){ 
      return x;
    } 
    int i = 1;
    int result = 1;
    
    while(result <= x){
      i++;
      result = i * i;
    }
    if((i - 1) * (i - 1) != x){
      i = 1; 
    }
    return i - 1;
}

