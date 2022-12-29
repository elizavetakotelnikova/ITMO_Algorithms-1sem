//check balance
#include <iostream>
using namespace std;
struct Node {
    struct Node *left = NULL, *right = NULL;
    int key;
    int height = 0;
    int balance = 0;
};
struct Binary_Tree {
    struct Node *root;
    int height;
};
int find_height(Node *root) {
    if (root == NULL) {
        return 0;
    }
    else {
        root->height = max(find_height(root->left), find_height(root->right)) + 1;
        if (root->right == NULL && root->left == NULL) {
            root->balance = 0;
        }
        else if (root->left == NULL) {
            root->balance = root->right->height;
        }
        else if (root->right == NULL) {
            root->balance = -1*root->left->height;
        }
        else {
            root->balance = root->right->height - root->left->height;
        }
    }
    return root->height;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,  ind_l, ind_r;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    Node *Bt;
    Bt = new Node[n];
    for (int i = 0; i < n; i++) {
        cin >> Bt[i].key >> ind_l >> ind_r;
        ind_l -= 1;
        ind_r -= 1;
        if (ind_l != -1) {
            Bt[i].left = &Bt[ind_l];
        }
        if (ind_r != -1) {
            Bt[i].right = &Bt[ind_r];
        }
    }
    int height_tr = find_height(&Bt[0]);
    for (int j = 0; j < n; j++) {
            cout << Bt[j].balance << "\n";
    }
    return 0;
}
