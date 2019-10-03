char *mx_strcpy(char *dst, const char *src){
	char *s = dst;

	while((*dst++ = *src++));
	return s;
}