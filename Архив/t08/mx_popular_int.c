int mx_popular_int(const int *arr, int size);

int mx_popular_int(const int *arr, int size) {
    int el = 0;
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        int tempEl = arr[i];
        int tempC = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == tempEl) {
                tempC++;
            }
        }
        if (tempC > count) {
            el = tempEl;
            count = tempC;
        }
    }
    return el;
}

