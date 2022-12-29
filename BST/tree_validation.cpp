//Tree validation (Проверка корректности)

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key, l, r;
    Node *left = NULL, *right = NULL;
};

void Inorder_traversal(Node* node, vector <int> &values)
{
    if (node != NULL) {
        Inorder_traversal(node->left, values);
        values.push_back(node->key);
        Inorder_traversal(node->right, values);
    }
}

int main() {
    int n, key, input, ind_l, ind_r;
    bool is_tree = true;
    vector <int> values;
    cin >> n;
    if (n == 0 or n == 1) {
        cout << "YES";
        return 0;
    }
    Node *Bt;
    Bt = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> Bt[i].key >> Bt[i].l >> Bt[i].r;
    }
    for (int i = 0; i < n; i++) {
        Bt[i].l--;
        ind_l = Bt[i].l;
        Bt[i].r--;
        ind_r = Bt[i].r;
        if (ind_l != -1) {
            Bt[i].left = &Bt[ind_l];
            if (Bt[ind_l].key >= Bt[i].key) {
                is_tree = false;
                cout << "NO";
                return 0;
            }
        }
        if (ind_r != -1) {
            Bt[i].right = &Bt[ind_r];
            if (Bt[ind_r].key <= Bt[i].key) {
                is_tree = false;
                cout << "NO";
                return 0;
            }
        }
    }
    Inorder_traversal(&Bt[0], values);
    for (int i = 0; i < n-1; i++) {
        if (values[i] >= values[i+1]) {
            is_tree = false;
            break;
        }
    }
    if (!is_tree) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    return 0;
}
