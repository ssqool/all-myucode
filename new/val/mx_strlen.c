int mx_strlen(const char *str);
int mx_strlen(const char *str) {
    int i = 0;
    while (*(str+i) != '\0') {
        i++;
    }
    return i;
}
