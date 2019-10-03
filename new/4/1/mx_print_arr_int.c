#include <unistd.h>
#include "mx_printint.c"
//#include "mx_printchar.c"

//void mx_printint(int n);
//void mx_printchar(char c);

 void mx_print_arr_int(const int *arr, int size){
 	for(int i = 0; i < size; ++i){
 		mx_printint(arr[i]);

 		//mx_printint(*(arr+i));
 	}
 }
 int main(){
 	const int g[]={0,2,3,4,5,6};
 	mx_print_arr_int(g, 10);
 }