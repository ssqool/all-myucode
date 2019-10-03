int mx_count_words(const char *str, char delimiter);

int mx_count_words(const char *str, char delimiter) {
    int count = 0;

    if (*str != '\0'){
        count = 1;
    }
    while (*str != '\0'){
        if (*str == delimiter && *str + 1 != '\0') {
            count++;
        }
    }
    return count;
}

