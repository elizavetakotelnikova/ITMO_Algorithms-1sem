//Two traversals (Два обхода)

#include <iostream>
using namespace std;

void find_postordertraversal(int values[], int &i, const int size, int min, int max) {
    if (i >= size)
        return;
    else if ((values[i] > max) or (values[i] < min))
        return;
    int parent = values[i];
    i++;
    find_postordertraversal(values, i, size, min, parent);
    find_postordertraversal(values, i, size, parent, max);
    cout << parent << " ";
}
int main() {
    int n, number;
    int min = -1;
    int max = 10000000;
    cin >> n;
    int values[n];
    if (n == 1) {
        cin >> values[0];
        cout << values[0];
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        if (values[i] > max) {
            max = values[i];
        }
        else if (values[i] < min) {
            min = values[i];
        }
    }
    int i = 0;
    find_postordertraversal(values, i, n, min, max);
    return 0;
}
