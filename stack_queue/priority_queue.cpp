//Priority queue (Приоритетная очередь)
#include <iostream>
#include <vector>
using namespace std;

void siftDown(vector <int> &queue, int i) {
    int left, right, j;
    int heapsize = queue.size();
    while (2 * i + 1 < heapsize) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < heapsize and queue[right] < queue[left]) {
            j = right;
        }
        if (queue[i] <= queue[j]) {
            break;
        }
        swap(queue[i], queue[j]);
        i = j;
    }
}

void siftUp(vector <int> &queue, int i) {
    while (queue[i] < queue[(i - 1) / 2]) {
        swap(queue[i], queue[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void push(vector<int> &queue, int key) {
    int heapsize = queue.size();
    if (heapsize == 0) {
        queue.push_back(key);
    } else {
        queue.push_back(key);
        siftUp(queue, queue.size() - 1);
    }
}

void extract_min(vector <int> &queue) {
    if (queue.size() == 0) {
        cout << "*" << "\n";
        return;
    }
    int min = queue[0];
    queue[0] = queue[queue.size() - 1];
    queue.pop_back();
    siftDown(queue, 0);
    cout << min << "\n";
}

void decrease_key(vector<int> &queue, vector<int> &stream, int index, int new_value) {
    int size = queue.size();
    int i, act_val;
    act_val = stream[index-1];
    for (i = 0; i < size; i++) {
        if (queue[i] == act_val) {
            queue[i] = new_value;
            stream[index-1] = new_value;
            break;
        }
    }
    siftUp(queue, i);
}

int main() {
    string command;
    int number, second;
    vector <int> queue;
    vector <int> stream;
    while (cin >> command) {
        if (command == " ") {
            break;
        }
        if (command == "push") {
            cin >> number;
            push(queue, number);
            stream.push_back(number);
        }
        else {
            if (command == "decrease-key") {
                cin >> number >> second;
                decrease_key(queue, stream, number, second);
                stream.push_back(0);
            }
            if (command == "extract-min") {
                extract_min(queue);
                stream.push_back(0);
            }
        }
    }
    return 0;
}
