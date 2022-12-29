//tree height (Высота дерева)

#include <iostream>
using namespace std;
struct Node {
    struct Node *left, *right;
    int key;
    int height;
    int l;
    int r;
};
struct Binary_Tree {
    struct Node *root;
    int height;
};
int main() {
    int n, key, input, ind_l, ind_r, height_tr;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    Node *Bt;
    Bt = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> Bt[i].key >> Bt[i].l >> Bt[i].r;
    }
    Bt[0].height = 1;
    height_tr = 1;
    for (int i = 0; i < n; i++) {
        ind_l = Bt[i].l - 1;
        ind_r = Bt[i].r - 1;
        if (ind_l != -1) {
            Bt[ind_l].height = Bt[i].height + 1;
            if (Bt[ind_l].height > height_tr) {
                height_tr = Bt[ind_l].height;
            }
        }
        if (ind_r != -1) {
            Bt[ind_r].height = Bt[i].height + 1;
            if (Bt[ind_r].height > height_tr) {
                height_tr = Bt[ind_r].height;
            }
        }
    }
    cout << height_tr;
    return 0;
}
