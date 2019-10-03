#include <iostream>
#include <ctime>

using namespace std;

size_t max(int *a, size_t length) {
    size_t max = 0;
    size_t len = length;
    for(size_t n = 0; n < len; n++) {
        if(a[n] > a[max]) max = n;
    }

    return max;
}

void selecton_sort(int *a, size_t length) {
    for(size_t n = length; n > 0; n--) {
        size_t max_id = max(a, n);
        int t = a[n - 1];
        a[n - 1] = a[max_id];
        a[max_id] = t;
    }
}

void print_ary(int *a, size_t length) {
    for(size_t i = 0; i < length; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main() {
    int a[30];
    size_t length = sizeof(a)/sizeof(a[0]);
    srand(time(nullptr));
    for(size_t i = 0; i < length; i++) {
        a[i] = rand() / ((RAND_MAX + 1u)/30);
    }
    print_ary(a, length);
    selecton_sort(a, length);
    print_ary(a, length);

    return 0;
}