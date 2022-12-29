//Segment tree

#include <iostream>
using namespace std;
void Update(int tree[], int value, int i, int left, int right, int place, int array[]) {
    if (right == left)  {
        array[place] += value;
        //cout << tree[i];
        tree[i] += value;
        //cout << i << tree[i] << value;
        return;
    }
    int mid = (left + right) / 2;
    if (place <= mid) {
        Update(tree, value, 2*i + 1, left, mid, place, array);
    }
    else {
        Update(tree, value, 2*i + 2, mid + 1, right, place, array);
    }
    tree[i] = tree[2*i + 1] + tree[2*i + 2];
}
/*void ChangeElement(int tree[], int value, int i, int left, int right, int flag, int place, int array[], int modify[]) {
    if (right == left)  {
        if (flag == 1) {
            tree[i] = 0;
            array[place] = 0;
        }
        array[place] += value;
        tree[i] += value;
        return;
    }
    int mid = (left + right) / 2;
    if (place <= mid) {
        ChangeElement(tree, value, 2*i + 1, left, mid, flag, place, array, modify);
    }
    else {
        ChangeElement(tree, value, 2*i + 2, mid, right, flag, place, array, modify);
    }
    tree[i] = tree[2*i + 1] + tree[2*i + 2];
}*/

int GetValue(int tree[], int i, int Left, int Right, int l, int r) {
    if (((r < Left) || (Right < l))) {
        return 0;
    }
    if ((l <= Left) && (Right <= r)) {
        //cout << i << Left << Right << " " << l << r << " ";
        return tree[i];
    }
    int mid = (Left + Right) / 2;
    int child_one = GetValue(tree, 2 * i + 1, Left, mid,  l, r);
    int child_two = GetValue(tree, 2 * i + 2, mid + 1, Right, l, r);
    return (child_one + child_two);
}
int main() {
    int n, k, pieces, number, left_s, right_s, diff;
    char flag;
    cin >> n >> k;
    int tree[4*n];
    int array[n];
    for (int i = 0; i < 2*n; i++) {
        array[i] = 0;
    }
    for (int i = 0; i < 4*n; i++) {
        tree[i] = 0;
    }
    for (int j = 0; j < k; j++){
        cin >> flag;
        if (flag == '+'){
            cin >> number >> pieces;
            if (number >= 1 and number <= n) {
                //cout << tree[12];
                Update(tree, pieces, 0, 0, n - 1, number - 1, array);
            }
        }
        else if (flag == '-'){
            cin >> number >> pieces;
            if (number >= 1 and number <= n) {
                if ((array[number - 1] - pieces) < 0) {
                    Update(tree, -1*array[number - 1], 0, 0, n - 1, number - 1, array);
                }
                else {
                    Update(tree, -1*pieces, 0, 0, n - 1, number - 1, array);
                }
            }
        }
        else if (flag == '?') {
            cin >> left_s >> right_s;
            if (left_s <= 0)
            {
                left_s = 1;
            }
            left_s -= 1;
            right_s -= 1;
            cout << GetValue(tree, 0, 0, n - 1, left_s, right_s) << "\n";
        }
    }
    return 0;
}
