//BST (Простое двоичное дерево поиска)

#include <iostream>
using namespace std;

struct Node{
    struct Node *left;
    struct Node *right;
    int key;
    Node(int value) {
        left = NULL;
        right = NULL;
        key = value;
    }

};

struct Binary_Tree{
    struct Node *root;

};

void insert(Node *node_tr, int value){
    if (value < node_tr->key) {
        if (node_tr->left != NULL){
            insert(node_tr->left, value);
        } else {
            node_tr->left = new Node(value);
        }
    } else if (value >= node_tr->key){
        if (node_tr->right != NULL){
            insert(node_tr->right, value);
        } else {
            node_tr->right = new Node(value);
        }
    }
};
void insert_new(Binary_Tree *Bt, int value){
    if (Bt->root != NULL){
        insert(Bt->root, value);
    } else {
        Bt->root = new Node(value);
    }
}

Node *minimum(Node *node_tr){
    if (node_tr->left == NULL){
        return node_tr;
    }
    return minimum(node_tr->left);
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
        node_tr->key = (minimum(node_tr->right))->key;
        node_tr->right = delete_node(node_tr->right, node_tr->key);
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
    return node_tr;
};
void delete_new(Binary_Tree *Bt, int value) {
    if (Bt->root != NULL) {
            Bt->root = delete_node(Bt->root, value);
        }
    }
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
Node *next(Node *root, int x) {
    Node* current = root, *successor = NULL;
    while (current != NULL) {
        if (current->key > x) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        };
    };
    return successor;
}
Node *prev(Node *root, int x) {
    Node* current = root, *successor = NULL;
    while (current != NULL) {
        if (current->key < x) {
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return successor;
}

int main() {
    string command;
    int number;
    bool exists_node;
    struct Binary_Tree Bt;
    Bt.root = NULL;
    while (cin >> command) {
        if (command == " ") {
            break;
        }
        if (command == "insert") {
            cin >> number;
            if (!exists(Bt.root, number)) {
                insert_new(&Bt, number);
            }
        }
        else if (command == "delete") {
            cin >> number;
            delete_new(&Bt, number);
        }
        else if (command == "exists") {
            cin >> number;
            exists_node = exists(Bt.root, number);
            if (exists_node) {
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        else if (command == "next") {
            cin >> number;
            Node* next_node = next(Bt.root, number);
            if (next_node != NULL) {
                cout << next_node->key << "\n";
            }
            else {
                cout << "none" << "\n";
            }
        }
        else if (command == "prev") {
            cin >> number;
            Node* prev_node = prev(Bt.root, number);
            if (prev_node != NULL) {
                cout << prev_node->key << "\n";
            }
            else {
                cout << "none" << "\n";
            }
        }
    }
    return 0;
}
