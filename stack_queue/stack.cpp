//Stack

#include <iostream>
using namespace std;
struct Node {
    int data ;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Stack {
    Node *head = NULL;
};

void Push(Stack *S, int value) {
    Node *new_node = new Node(value);
    new_node->data = value;
    new_node->next = S->head;
    S->head = new_node;
}
void Pop(Stack *S) {
    struct Node *deleted = S->head;
    if (deleted == NULL) {
        return;
    }
    cout << deleted->data << "\n";
    S->head = deleted->next;
    free(deleted);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct Stack S;
    int n, add;
    char flag;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> flag;
        if (flag == '+'){
            cin >> add;
            Push(&S, add);
        }
        else if (flag == '-'){
            Pop(&S);
        }
    }
    return 0;
}
