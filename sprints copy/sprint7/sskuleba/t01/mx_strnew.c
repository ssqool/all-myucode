#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size){
	if(size < 0)
		return NULL;
	char *wds = (char*) malloc(size + 1);
	if (wds == NULL) 
		return NULL;
	for(int i =0; i < size; i++)
		wds[i] = '\0';
	return wds;
}

 int main(void){
 	const int size = 20;
 	char *g = mx_strnew(size);
 	for(int i = 0; g[i] == '\0'; i++){
 		printf("%d\n", i);
 	}
 }
