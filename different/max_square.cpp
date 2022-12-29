//Maximal square, memory limit (Максимальная сторона квадрата, лимит по памяти)
#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
    int n, m;
    string str;
    bool flag;
    int counter_max = 0;
    int x, y = 0;
    cin >> n >> m;
    int array[2][m];
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int k = 0; k < m; k++) {
            unsigned char a;
            a = str[k];
            array[1][k] = a - '0';
        }
        for (int j = 0; j < m; j++) {
            if (array[1][j] == 1) {
                array[1][j] = 0;
            }
            else {
                if (j == 0 or i == 0) {
                    array[1][j] = 1;
                }
                else {
                    array[1][j] = 1;
                    array[1][j] += min(min(array[0][j-1], array[0][j]), array[1][j-1]);
                }
            }
            if (array[1][j] >= counter_max) {
                counter_max = array[1][j];
                y = j - counter_max + 2;
                x = i - counter_max + 2;
            }
        }
        for (int k = 0; k < m; k++) {
            array[0][k] = array[1][k];
        }
    }
    cout << counter_max << " " << x << " " << y;
    return 0;
}
