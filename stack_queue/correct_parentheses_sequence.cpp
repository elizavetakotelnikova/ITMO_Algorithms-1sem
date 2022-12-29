//Correct barentheses sequence (Правильная скобочная последовательность)

#include <iostream>
#include <string>
using namespace std;
struct Node {
    char data ;
    Node *next;
    Node (char value)
    {
        data = value;
        next = NULL;
    }
};

struct Stack {
    Node *head = NULL;
};

void Push(Stack *S, char value) {
    Node *new_node = new Node(value);
    new_node->data = value;
    new_node->next = S->head;
    S->head = new_node;
}
bool Pop(Stack *S, char k) {
    struct Node *deleted = S->head;
    if (deleted == NULL) {
        return false;
    }
    if (S->head->data != k) {
        S->head = deleted->next;
        free (deleted);
        return false;
    }
    else {
        S->head = deleted->next;
        free (deleted);
        return true;
    }
}
bool Is_empty(Stack *S) {
    if (S->head == NULL) {
        return true;
    }
    return false;
}
void Check(string str) {
    struct Stack S;
    char add;
    bool flag;
    if (str.length() % 2 != 0)
    {
        cout << "NO" << "\n";
        return;
    }
    for (int i = 0; i < str.length(); i++) {
        add = str[i];
        if (add == '(' or add == '[') {
            Push(&S, add);
        } else {
            if (add == ']') {
                flag = Pop(&S, '[');
                if (!flag) {
                    cout << "NO" << "\n";
                    return;
                }
            } else {
                flag = Pop(&S, '(');
                if (!flag) {
                    cout << "NO" << "\n";
                    return;
                }
            }
        }
    }
    if (Is_empty(&S)) {
        cout << "YES" << "\n";
        return;
    }
    else {
        cout << "NO" << "\n";
        return;
    }
}
int main(){
    cin.tie(nullptr);
    string str;
    while (getline(cin, str)) {
        if (str.empty()) { break; }
        Check(str);
    }
    return 0;
}
