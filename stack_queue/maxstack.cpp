//Maxstack (Макстек)

#include <iostream>
using namespace std;
struct Node {
    int data ;
    Node *next;
    int maxstack_node;
    Node(int value)
    {
        data = value;
        next = NULL;
        maxstack_node = 0;
    }
};

struct Stack {
    Node *head = NULL;
    int maxstack = 0;
};

void Push(Stack *S, int value) {
    Node *new_node = new Node(value);
    new_node->data = value;
    new_node->next = S->head;
    if (value > S->maxstack) {
        S->maxstack = value;
        new_node->maxstack_node = value;
    }
    else {
        new_node->maxstack_node = S->maxstack;
    }
    S->head = new_node;
}
void Pop(Stack *S) {
    struct Node *deleted = S->head;
    if (deleted == NULL) {
        return;
    }
    if (deleted->data == S->maxstack) {
        if (deleted->next == NULL) {
            S->maxstack = 0;
        } else {
            S->maxstack = deleted->next->maxstack_node;
        }
    }
    S->head = deleted->next;
    free (deleted);
}
bool Is_empty(Stack *S) {
    if (S->head == NULL) {
        return true;
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    struct Stack S;
    int n, add;
    string flag;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> flag;
        if (flag[0] == '+'){
            cin >> add;
            Push(&S, add);
        }
        else if (flag[0] == '-'){
            Pop(&S);
        }
        if (flag == "max") {
            if (Is_empty(&S)) {
                continue;
            }
            cout << S.maxstack << "\n";
        }
    }
    return 0;
}
