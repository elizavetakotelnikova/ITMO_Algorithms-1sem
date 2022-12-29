//Ordered set using an AVL tree (Упорядоченное множество на АВЛ-дереве)
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
    }
    return root->height;
}
void fixheight (Node *p)
{   int hl = 0;
    int hr = 0;
    if (p->left != NULL) {
        hl = p->left->height;
    }
    if (p->right != NULL) {
        hr = p->right->height;
    }
    p->height = max(hl,hr) + 1;
}
int find_balance(Node *root) {
    if (root == NULL) {
        return 0;
    }
    else {
        if (root->right == NULL && root->left == NULL) {
            root->balance = 0;
        }
        else if (root->left == NULL) {
            root->balance = root->right->height;
        }
        else if (root->right == NULL) {
            root->balance = 0 - root->left->height;
        }
        else {
            root->balance = root->right->height - root->left->height;
        }
    }
    find_balance(root->left);
    find_balance(root->right);
    return root->balance;
}
Node* small_rotate_left(Node *a) {
    Node *b = a->right;
    a->right = b->left;
    b->left = a;
    fixheight(a);
    fixheight(b);
    return b;
}
Node* small_rotate_right(Node *a) {
    Node *b = a->left;
    a->left = b->right;
    b->right = a;
    fixheight(a);
    fixheight(b);
    return b;
}
Node* bigRotateLeft(Node *a) {
    a->right = small_rotate_right(a->right);
    a = small_rotate_left(a);
    return a;
}
Node* bigRotateRight(Node *a) {
    a->left = small_rotate_left(a->left);
    a = small_rotate_right(a);
    return a;
}
int find_balance_one(Node *p) {
    if (p->right == NULL && p->left == NULL) {
        return 0;
    }
    else if (p->left == NULL) {
        return p->right->height;
    }
    else if (p->right == NULL) {
        return (0 - p->left->height);
    }
    else {
        return (p->right->height - p->left->height);
    }
}
Node* fix_balance(Node* p) {
    fixheight(p);
    p->balance = find_balance_one(p);
    if (p->balance == 2) {
        if (find_balance_one(p->right) < 0) {
            return(bigRotateLeft(p));
        }
        else {
            return(small_rotate_left(p));
        }
    }
    if (p->balance == -2) { 
        if (find_balance_one(p->left) > 0) {
            return (bigRotateRight(p));
        }
        else {
            return(small_rotate_right(p));
        }
    }
    return p;
}
Node* insert(Node *node_tr, int value){
    if (node_tr == NULL) {
        node_tr = new Node;
        node_tr->key = value;
        node_tr->left = NULL;
        node_tr->right = NULL;
        node_tr->balance = 0;
        node_tr->height = 1;
        return node_tr;
    }
    if (value < node_tr->key) {
        node_tr->left = insert(node_tr->left, value);
    }
    else {
        node_tr->right = insert(node_tr->right, value);
    }
    return fix_balance(node_tr);
};
Node *maximum(Node *node_tr){
    if (node_tr->right == NULL){
        return node_tr;
    }
    return maximum(node_tr->right);
}
Node* delete_node(Node *node_tr, int z) {
    if (node_tr == NULL){
        return node_tr;
    }
    if (z < node_tr->key) {
        node_tr->left = delete_node(node_tr->left, z);
    }
    else if (z > node_tr->key) {
        node_tr->right = delete_node(node_tr->right, z);
    }
    else if ((node_tr->left != NULL) && (node_tr->right != NULL)){
        node_tr->key = (maximum(node_tr->left))->key;
        node_tr->left = delete_node(node_tr->left, node_tr->key);
    }
    else {
        if (node_tr->left != NULL) {
            node_tr = node_tr->left;
        }
        else if (node_tr->right != NULL) {
            node_tr = node_tr->right;
        }
        else {
            node_tr = NULL;
        }
    }
    if (node_tr == NULL) {
        return node_tr;
    }
    return fix_balance(node_tr);
};
bool exists(struct Node *node_tr, int x) {
    if (node_tr == NULL) {
        return false;
    }
    if (x == node_tr->key) {
        return true;
    }
    if (x < node_tr->key) {
        return exists(node_tr->left, x);
    }
    else {
        return exists(node_tr->right, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string command;
    int n, number;
    bool exists_node;
    struct Binary_Tree Bt;
    Bt.root = NULL;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "A") {
            cin >> number;
            if (!exists(Bt.root, number)) {
                Bt.root = insert(Bt.root, number);
            }
            Bt.root->balance = find_balance_one(Bt.root);
            cout << Bt.root->balance << "\n";
        }
        else if (command == "D") {
            cin >> number;
            if (Bt.root == NULL) {
                cout << 0 << "\n";
            }
            else {
                Bt.root = delete_node(Bt.root, number);
                if (Bt.root == NULL) {
                    cout << 0 << "\n";
                }
                else {
                    Bt.root->balance = find_balance_one(Bt.root);
                    cout << Bt.root->balance << "\n";
                }
            }
        }
        else if (command == "C") {
            cin >> number;
            exists_node = exists(Bt.root, number);
            if (exists_node) {
                cout << "Y" << "\n";
            }
            else {
                cout << "N" << "\n";
            }
        }

    }
    return 0;
}
