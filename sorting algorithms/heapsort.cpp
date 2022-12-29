#include <iostream>
using namespace std;
void siftdown(int array[], int n, int i) {
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n and array[l] > array[max])
        max = l;
    if (r < n and array[r] > array[max])
        max = r;
    if (max != i) {
        swap(array[i], array[max]);
        siftdown(array, n, max);
    }
}
void buildHeap(int n, int array[]) {
    int heapsize = n;
    int i = heapsize / 2;
    while (i >= 0) {
        siftdown(array, n, i);
        i--;
    }
}
void heapsort(int array[], int n) {
    buildHeap(n, array);
    int heapsize = n;
    for (int i = 0; i < n - 1; i++) {
        swap(array[0], array[n-1-i]);
        heapsize--;
        siftdown(array, heapsize, 0);
    }
}
int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    heapsort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
