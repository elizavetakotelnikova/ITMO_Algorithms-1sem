//Filling the tree (Заполнение дерева)

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key = -1, l, r;
    Node *left = NULL, *right = NULL;
};

void Inorder_traversal(Node* node, int &i)
{
    if (node != NULL) {
        Inorder_traversal(node->left, i);
        if (node->key == -1) {
            node->key = i;
            i++;
        }
        Inorder_traversal(node->right, i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ind_l, ind_r;
    cin >> n;
    Node *Bt;
    Bt = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> Bt[i].l >> Bt[i].r;
        Bt[i].l--;
        ind_l = Bt[i].l;
        Bt[i].r--;
        ind_r = Bt[i].r;
        if (ind_l != -1) {
            Bt[i].left = &Bt[ind_l];
        }
        if (ind_r != -1) {
            Bt[i].right = &Bt[ind_r];
        }
    }
    int i = 1;
    Inorder_traversal(&Bt[0], i);
    for (int i = 0; i < n; i++) {
        cout << Bt[i].key << " ";
    }
        return 0;
}
