//Queue (очередь)

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Queue {
    Node *head = NULL, *tail = NULL;
};

void Enqueue(Queue *Q, int value)
{
    Node *new_node = new Node(value);
    if (Q->tail == NULL) {
        Q->head = Q->tail = new_node;
        return;
    }
    Q->tail->next = new_node;
    Q->tail = new_node;
};

void Dequeue(Queue *Q)
{
    if (Q->head == NULL)
        return;
    Node *for_delete = Q->head;
    cout << Q->head->data << '\n';
    Q->head = Q->head->next;
    if (Q->head == NULL)
        Q->tail = NULL;
    delete (for_delete);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    struct Queue Q;
    int n, add;
    char flag;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> flag;
        if (flag == '+') {
            cin >> add;
            Enqueue(&Q, add);
        }
        else {
            Dequeue(&Q);
        }

    }
    return 0;
}
