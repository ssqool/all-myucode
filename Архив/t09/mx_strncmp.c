int mx_strncmp(const char *s1, const char *s2, int n);

int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;
    
    while (*s1 != '\0' && *s2 != '\0' && i != n) {
        if (*s1 > *s2) {
            return 1;
        } else if (*s1 < *s2) {
            return -1;
        }
        i++;
    }
    if(*s1 == *s2){
        return 0;
    }
    return 0; 
}



